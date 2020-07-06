// MCA Project NLP Information Retrieval objects / NLPIROBJ -*- C++ -*-
// Submitted by Sourabh Roy MCA Final Year
// Batch 2017-2020
// Pondicherry University, Karaikal Campus

//This file is part of NLP Information Retrieval objects  -*- C++ -*- Header file

//    NLP Information Retrieval objects / NLPIROBJ  is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    NLP Information Retrieval objects is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with NLP Information Retrieval objects.  If not, see <https://www.gnu.org/licenses/>.


/*
 *  This is a beta NLPIROBJ C++ Library header.
 */

#ifndef __NLPIROBJ
#define __NLPIROBJ 1
#if __cplusplus < 201103L
#error FATAL ERROR!!  use of backdate GCC version 
#endif
#ifndef _GLIBCXX_IOSTREAM
#include<iostream>
#define _GLIBCXX_IOSTREAM 1
#endif
#ifndef _GLIBCXX_VECTOR
#include<vector>
#define _GLIBCXX_VECTOR 1
#endif
#ifndef _GLIBCXX_CMATH
#include<cmath>
#define _GLIBCXX_CMATH 1
#endif
#ifndef _GLIBCXX_UNORDERED_MAP
#include<unordered_map>
#define _GLIBCXX_UNORDERED_MAP 1
#endif
#ifndef _GLIBCXX_STRING
#include<string>
#define _GLIBCXX_STRING 1
#endif
#ifndef _GLIBCXX_UTILITY
#include<utility>
#define _GLIBCXX_UTILITY 1
#endif
#ifndef _GLIBCXX_THREAD
#include<thread>
#define _GLIBCXX_THREAD 1
#endif
#define RAD_1 57.296
#define LOG_10 0.301029f
#define lowcase(c) (((c)>='A' and (c)<='Z')?((c)+'a'-'A'):(c))
namespace aether
{
class wordbag
{
    std::unordered_map < std::string , std::pair < long double , long double > > _a;
    public:
    wordbag ();
    wordbag ( const std::unordered_map < std::string , std::pair < long double, long double > >& );
    ~wordbag ();
    void operator = ( const std::unordered_map < std::string , std::pair < long double, long double > >& );
    double cosine () const;
    double jaccard () const;
    std::unordered_map < std::string , std::pair < long double, long double > > transform_tfidf () const;
    friend std::ostream& operator << (  std::ostream& , const wordbag& );
};

class word_to_vec
{
    std::string text;
    void word_vec ( std::unordered_map< std::string , unsigned long >&) const;
    public:
    word_to_vec ();
    word_to_vec (const std::string& );
    ~word_to_vec ();
    void operator = ( const std::string& );
    friend std::ostream& operator << ( std::ostream& , const word_to_vec& );
    friend std::unordered_map < std::string , std::pair < long double, long double > > generate_wordbag ( const word_to_vec& , const word_to_vec& );
};
}

#endif // end NLPIROBJ header