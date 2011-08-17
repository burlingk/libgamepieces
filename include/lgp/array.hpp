/// \file lgp_array.hpp
/// \brief An attempt to leverage the benefits of both an array and a linked list.
/// \author Kenneth. M. Burling Jr. (a.k.a Emry)
/// \version Alpha-0.001
///
/// copyright: Copyright &copy; 2008, 2009, 2010 K. M. Burling Jr.<br>
///            All Rights Reserved
///
/// Redistribution and use in source and binary forms, with or without modification, are permitted provided that
/// the following conditions are met:
///
/// * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
/// * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
///   disclaimer in the documentation and/or other materials provided with the distribution.
/// * Neither the name of the libgamepieces project team, nor the names of its contributors may be used to endorse or
///   promote products derived  from this software without specific prior written permission.
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
/// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
/// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
/// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
/// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
/// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
/// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
///  class lgp::Array is an attempt to leverage the good points of a linked list
///  As well as the good points of an array.  The main bad point of a linked list
///  is access time of a variable.  If you want to access a variable, you either have
///  to already have a pointer to that variable, or you have to iterate through the list
///  to find it.  Arrays on the other hand are very fast to access anything.  The problem
///  with an array comes into play when you deal with memory management.  In order to
///  expand an array, you have to make a larger array and then copy the contents of the old
///  array into the new array.  This is time consuming, and takes more time as the array
///  grows.
///
///  When creating methods to add, search, manipulate and sort data, both of these issues
///  can have a major effect on the design patterns used.  Having to totally recreate and move
///  an array every time it needs to be larger can be time consuming.  Not to mention the fact that
///  in order to do this efficiently, large amounts of unused memory must  be set aside for the new
///  array.  This is the problem with std::vector.  It operates in this manner.
///
///  However, because of the seek and access nature of a linked list, algorithms such as a binary
///  search become useless.  The entire point is to pick and choose values out of the middle so that
///  you cut down on the number of comparisons, and thus the access time required to locate a value.
///  With a linked list, you have to seek to the location of the values each time anyway.  Even if
///  you use a double linked linked list and seek back and forth that way, you are still going back
///  and forth with useless passes.  An algorithm that should have made things more efficient is
///  suddenly taking longer than a single linear search.
///
///  So, my proposed solution is this.  An Array class that creates a list of arrays (blocks of memory)
///  and as the array needs to expand, rather than totally recreate the entire array, it adds a new
///  block of memory on the end.
///
///  Locating a requested index becomes a matter of integer math.  index/blockSize returns the
///  array that the index is in, and index % blockSize returns the index of the variable in that
///  array.  This makes the access time just slightly less efficient than a normal array, but much
///  more efficient than a linked list.
///
///  This method of memory allocation means that each time the Array becomes full, it only needs
///  to create a new block of memory.  It does not need to move everything that was already in the
///  old one.  Everything can stay right where it was.  This method does mean however that pointer
///  based iterators will not be as effective as they would be with a vector, because they are not 100%
///  contiguous.  Old fashioned integers will work better.
///
/// File last updated 14:35 UTC on 13 Jan 2011

#ifndef LGP_ARRAY_HPP_
#define LGP_ARRAY_HPP_

#include <iostream>

#include <lgp/exceptions.hpp>

namespace lgp
{
  /// \brief An attempt to leverage the benefits of both an array and a linked list.
  ///
  /// In it's current form it will behave in  most ways like a normal array.
  /// The main difference being that Array a[0] should not be treated as a pointer
  /// to an array.
  template <class T>
  class Array
  {
    protected:
    //Data dealing with the invisible part of things
    T** arrayListPtrM;         ///< \brief The array of arrays.
    int arrayListCapacityM;    ///< \brief How many arrays the current array can hold.
    int blockSizeM;            ///< \brief How big each array should be.
    int blocksM;               ///< \brief How many arrays we already have.

    //Values pertaining to the Array as a whole
    T zeroValueM;             ///< \brief The default value for cells.  defaults to null.

    public:
    Array();                             ///< \brief Default constructor.  Will use default settings.
    Array(int blockSize, T zeroValue);   ///< \brief More controlled constructor.
    ~Array();                            ///< \brief Destructor
    void expand(void);                   ///< \brief Manually add an empty array to arrayListPtrM;
    int size(void);                      ///< \brief Returns the current capacity of the Array
    T& operator[](int index);            ///< \brief The [] operator.  Returns a reference to the indexed value.

	void reset();                         ///< \brief Reset the array to empty, with current settings.
	void reset(int blockSize, T zeroValue); ///< \brief Reset array with new settings.
  };  //end class Array

  /// The default constructor uses default values that may or may not suit your needs.
  /// I would suggest that you not use the default constructor.  If you do, feel free to
  /// make comments on the defaults so that we can consider changing them for future versions.
  ///
  /// blockSizeM = 25; zeroValue = NULL
  ///
  /// I figured these would be generic enough.  I am considering making the default block size
  /// larger though.  I will see how things work out.
  template <class T>
  Array<T>::Array()
   {
     blockSizeM = 25;
     blocksM = 1;
     zeroValueM = NULL;
     arrayListCapacityM = 100;

     arrayListPtrM = new T * [10];
     arrayListPtrM[0] = new T[25];

     for(int i = 0; i < 25; i++)
       {
         arrayListPtrM[0][i] = NULL;
       }
     return;
   } //end Array<T>::Array()

  /// This is a more appropriate constructor method.  Array(int blockSize, T zeroValue) allows
  /// the user to designate a value for blockSizeM, and a zeroValue.  The zeroValue is the default
  /// value that is set for all of the empty cells when a new array is created.  For numbers, the
  /// datatype specific equivalent of 0 (0, 0.00, etc) is appropriate.  For classes, either NULL
  /// or some appropriate "non-value" version of the class is appropriate.  For boolean values,
  /// use your best judgment.  It all depends on the type of program you are writing anyway.
  template <class T>
  Array<T>::Array(int blockSize, T zeroValue)
  {
        blockSizeM = blockSize;
        blocksM = 1;
        zeroValueM = zeroValue;
        arrayListCapacityM = 100;

        arrayListPtrM = new T*[10];
        arrayListPtrM[0] = new T[blockSize];

        for(int i=0; i < blockSize; i++)
        {
                arrayListPtrM[0][i] = zeroValue;
        }
        return;
  } // end Array<T>::Array(int blockSize, T zeroValue)

  /// The destructor is pretty straight forward.  Iterate through arrayListPtrM deleting
  /// each of the arrays, and then delete arrayListPtrM.  Doing anything further to the
  /// data held within the array is not within the perview of this constructor.  The
  /// code written here does not know if the values within each cell are classes or
  /// primitives.  If the code in each cell is a class, this code has no way of knowing
  /// if it was simply declared, or if it is a pointer to a on object allocated using new.
  /// The person writing the individual program needs to ensure that they delete created
  /// variables as needed.  This class will only clean up what it creates.  The same is
  /// true for arrays that are built into the programming language.
  template <class T>
  Array<T>::~Array()
  {
          for(int i=0; i < blocksM; i++)
          {
                  delete [] arrayListPtrM[i];
          }
          delete [] arrayListPtrM;
          return;
  } // end ~Array()



  /// This is probably the simplest method.  It just multiplies the number of blocks by their size.
  template <class T>
  int Array<T>::size(void)
  {
          return blockSizeM * blocksM;
  } //end Array<T>::size()



  /// operator[] uses simple math to determine the location of the data requested.
  /// First it uses integer division to determine which internal array that the
  /// requested value is in, then it uses modulus math to find out the index
  /// of the value within that array.
  ///
  /// At this time an OutOfRangeException is thrown if the user tries to access
  /// an index that is outside of the current capacity.  It has been suggested
  /// that I change this behavior to allocate enough space for the value to be
  /// valid.  I have mixed feelings on this.  Do let me know what you think.
  template <class T>
  T& Array<T>::operator[](int index)
  {
          /// \todo This part may change.  Perhaps it should automatically expand.
          if(index >= size() || index < 0)
          {
            throw OutOfRangeException() << throwing_function("lgp::Array::operator[]") << throwing_file("lgp_array.cpp");
          }

          else
          {
                  int listVal = index/blockSizeM;
                  int indexVal = index % blockSizeM;
                  return arrayListPtrM[listVal][indexVal];
          }
  } //end Array<T>[]



  /// Array::expand() first checks to see if there is enough space in arrayListPtrM to add
  /// another array pointer.  If there is not room, it makes room.  Once that is taken care
  /// of, it creates a new array and zeroes it out.
  template <class T>
  void Array<T>::expand(void)
  {
          //First check that the ArrayListPtrM array is large enough.
          if(blocksM == arrayListCapacityM)
          {
                  int newCapacity = arrayListCapacityM + 100;      //New Capacity Size
                  T** newList = new T*[newCapacity];              //Create the new list.
                  for (int i=0; i < arrayListCapacityM; i++)      //Populate the new list.
                  {
                          newList[i] = arrayListPtrM[i];
                  }
                  arrayListCapacityM = newCapacity;              //Assign the new capacity.
                  delete [] arrayListPtrM;                       //Delete the old list.
                  arrayListPtrM = newList;                       //Assign the new list to arrayListPtrM.
          }
          arrayListPtrM[blocksM] = new T[blockSizeM];        //Create the new array.
          for(int i=0; i < blockSizeM; i++)                  //Zero out the new array
          {
                  arrayListPtrM[blocksM][i] = zeroValueM;
          }
          blocksM++;                                         //Increment blocksM;
  }  //end Array::expand()

	 

	 
	 template <class T>
	 void Array<T>::reset() ///< Reset the array to empty.
	 {  
		  for(int i=0; i < blocksM; i++)
				{
					 std::cout << "Delete " << i << " in reser." <<std::endl;
					 delete [] arrayListPtrM[i];
				}

		  delete [] arrayListPtrM;

		  arrayListPtrM = new T*[100];
        arrayListPtrM[0] = new T[blockSizeM];

		  for(int i=0; i < blockSizeM; i++)
				{
					 arrayListPtrM[0][i] = zeroValueM;
				}
		  
		  blocksM = 1;
		  arrayListCapacityM = 100;
		  
		  return;
	 }

	 template <class T>
	 void Array<T>::reset(int blockSize, T zeroValue) ///< Reset the array to empty, and change the settings
	 {
		  blockSizeM = blockSize;
		  zeroValueM = zeroValue;
		  
		  for(int i=0; i < blocksM; i++)
				{
					 delete [] arrayListPtrM[i];
				}
		  delete [] arrayListPtrM;

		  arrayListPtrM = new T*[10];
        arrayListPtrM[0] = new T[blockSizeM];

		  for(int i=0; i < blockSizeM; i++)
				{
					 arrayListPtrM[0][i] = zeroValueM;
				}
		  
		  blocksM = 1;
		  arrayListCapacityM = 100;

		  return;
	 }


	 

} //end of namespace lgp

#endif /* LGP_ARRAY_HPP_ */


