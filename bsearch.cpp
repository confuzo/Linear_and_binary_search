#include <iostream>  // cout, endl
#include <algorithm> // copy
#include <iterator>  // ostream_iterator, begin(), end()

/// Implements an iterative linear seach on an range [first; last) of integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */
int * lsearch( int *first, int *last, int value )
{

    while(first != last){
      if (value == *first){
          return first;
      }
      first++;
    }
    return last; // STUB
}

/// Implements an interative binary search on an array of integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */
int * bsearch( int *first, int *last, int value )
{
  auto ini (first);
  auto end (last);

  while(ini != end){

    auto m = ini + ((end-ini)/2);
    if(*m == value){
      return m;
    }else if(value < *m){
      end = m;

    }else{
      ini = m++;
      if(ini == (last-1)){
        return last;
      }
    }
  }
  return last;
}


// Driver function.
int main()
{
    int A[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // Data container.
    int targets[] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 ,10, -4}; // Target values for testing.

    // Prints out the original data container.
    std::cout << "Array: [ ";
    std::copy( std::begin(A), std::end(A), std::ostream_iterator<int>( std::cout , " " ) );
    std::cout << "]\n";

    // Executes several searchs in the data container.
    for( const auto & e : targets )
    {
        // Look for target in the entire range.
        auto result = bsearch( std::begin(A), std::end(A), e );

        // Process the result
        if ( result != std::end(A) )
        {
            std::cout << ">>> Found \"" << e << "\" at position "
                      << std::distance(std::begin(A),result) << ".\n";
        }
        else
        {
            std::cout << ">>> Value \"" << e << "\" not found in array!\n";
        }
    }

    return 0;
}
