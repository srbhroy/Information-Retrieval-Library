//MCA Project NLP Information Retrieval objects / NLPIROBJ -*- C++ -*- Header file
// Submitted by Sourabh Roy MCA Final Year
// Batch 2017-2020
// Pondicherry University, Karaikal Campus

//This file is part of NLP Information Retrieval objects.

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

#include "nlpirobj.h"
namespace aether
{
template < int x > struct constant
{
  static constexpr int val = 1+constant < x-1 >::val ;
};
template <> struct constant < 0 >
{
  static constexpr int val = 0;
};
wordbag :: wordbag()
{}
wordbag :: wordbag( const std::unordered_map<std::string,std::pair< long double, long double>>& _x)
{
    if(!_x.empty())
        _a=_x;
    else
      std::cerr<<"ERROR !!!!(Empty vector assigned) at "<<__LINE__<<" in "<<__FUNCTION__<<'\n';
}
wordbag :: ~wordbag()
{}
void wordbag :: operator = ( const std::unordered_map<std::string,std::pair< long double, long double>>& _x)
{
    if(!_x.empty())
        _a=_x;
    else
       std::cerr<<"ERROR !!!!(Empty vector assigned) at "<<__LINE__<<" in "<<__FUNCTION__<<'\n';
}
 std::ostream& operator << ( std::ostream& i, const wordbag& j )
{
    for(auto k : j._a ) i << k.first << '\t' << ( k.second ).first << '\t' << ( k.second ).second << '\n';
    return i;
}

 double wordbag :: cosine() const
{
    if ( _a.empty() ) { std::cerr << "ERROR !!!!(Empty vector assigned) at "<<__LINE__<<" in "<<__FUNCTION__<<'\n' ; return 0; }
    long double sum = constant < 0 >::val;
    long double mod_a = constant < 0 >::val, mod_b = constant < 0 >::val;
    for( auto i = _a.begin(); i != _a.end(); ++i )
    {
        sum += ( ( i->second ).first * ( i->second ).second );
        mod_a += ( ( i->second ).first * ( i->second ).first );
        mod_b += ( ( i->second ).second * ( i->second ).second );
    }
    mod_a = sqrtl(fabsl(mod_a));
    mod_b = sqrtl( fabsl( mod_b ) );
    return constant < 100 >::val - ( constant < 100 >::val * ( ( RAD_1 * ( acos ( sum / ( mod_a * mod_b ) ) ) ) / constant < 90 >::val ) );
}
double wordbag :: jaccard() const
{   if( _a.empty() ) { std::cerr << "ERROR !!!!(Empty vector assigned) at "<<__LINE__<<" in "<<__FUNCTION__<<'\n'; return 0; }
    long double jac_a = constant < 0 >::val , jac_b = constant < 0 >::val;
    for( auto i =_a.begin(); i != _a.end(); ++i )
    {
        ++jac_b;
        if( ( i->second ).first > constant < 0 >::val && ( i->second ).second > constant < 0 >::val )
            ++jac_a;
    }
    return /*constant < 100 >::val - */( constant < 100 >::val * double( jac_a / jac_b ) );
}
std::unordered_map< std::string , std::pair< long double , long double > > wordbag :: transform_tfidf() const
{
    if( _a.empty() ) { std::cerr << "ERROR !!!!(Empty vector assigned) at "<<__LINE__<<" in "<<__FUNCTION__<<'\n'; }
    std::unordered_map< std::string , std::pair< long double, long double > > _t;
    long double siz = constant < 0 >::val , siz1 = constant < 0 >::val;
    for( auto i = _a.begin(); i != _a.end(); ++i )
    {
            siz += ( i->second ).first;
            siz1 += ( i->second ).second;
    }
    for( auto i = _a.begin(); i != _a.end(); ++i )
    {
        long double a = constant < 0 >::val , b , c , d;
        ( i->second ).first ? a += constant < 1 >::val : a;
        ( i->second ).second ? a += constant < 1 >::val : a;
        a == constant < 2 >::val ? a = LOG_10 : a = constant < 0 >::val;
        c = ( i->second ).first / siz;
        d = ( i->second ).second / siz1;
        _t[ i->first ] = std::make_pair(a*c,a*d);

    }
    return _t;
}















word_to_vec :: word_to_vec()
{ }
word_to_vec :: ~word_to_vec()
{ }
word_to_vec :: word_to_vec( const std::string& _t)
{
    text = _t;
}
void word_to_vec :: operator = ( const std::string& _t)
{
    text = _t;
}
std::ostream& operator << ( std::ostream& i, const word_to_vec& j )
{
    i<<j.text;
    return i;
}

void word_to_vec :: word_vec( std::unordered_map< std::string , unsigned long >& text_vec) const                                   //TIME COMPLEXITY - O(N) WHERE N = LENGTH OF THE DOCUMENT
{
    std::string data;
    unsigned long long i = constant < 0 >::val;
    std::unordered_map< char , bool > punct{
                                                  { '!', constant < 1 >::val },
                                                  { '-', constant < 1 >::val },
                                                  { ';', constant < 1 >::val },
                                                  { ':', constant < 1 >::val },
                                                  { '\'', constant < 1 >::val },
                                                  { '"', constant < 1 >::val },
                                                  { ',', constant < 1 >::val },
                                                  { '.', constant < 1 >::val },
                                                  { '?', constant < 1 >::val },
                                                  { '<', constant < 1 >::val },
                                                  { '>', constant < 1 >::val },
                                                  { '[', constant < 1 >::val },
                                                  { ']', constant < 1 >::val },
                                                  { '{', constant < 1 >::val },
                                                  { '}', constant < 1 >::val },
                                                  { '=', constant < 1 >::val },
                                                  { '`', constant < 1 >::val },
                                                  { '~', constant < 1 >::val },
                                                  { '$', constant < 1 >::val },
                                                  { '#', constant < 1 >::val },
                                                  { '(', constant < 1 >::val },
                                                  { ')', constant < 1 >::val }
                                };
    while( i < text.length() )
    {
        if( punct[ char( text[i] ) ] || text[i] == ' ')
        {
            if( !data.empty() && ( text[i]==' ' || text[i]=='.' || text[i]==',' || text[i]=='\n' ) )
            {
                text_vec[ data ] += constant < 1 >::val;
                data.erase();
            }
            ++i;
            continue;
        }
        if( ( text[ i ] >= constant < 65 >::val && text[ i ] < constant < 91 >::val ) || ( text[ i ] >= constant < 97 >::val && text[ i ] < constant < 123 >::val) || ( text[ i ] >= constant < 48 >::val && text[ i ] < constant < 58 >::val ) )
        {
                data += lowcase( text[ i ] );
                if( i + 1 == text.length() )
                {
                    text_vec[ data ] += constant < 1 >::val;
                    data.erase();
                }
                ++i;
        }
        else
            ++i;
    }
}

std::unordered_map< std::string , std::pair< long double, long double > > generate_wordbag( const word_to_vec& _T , const word_to_vec& _X )
{
        
    std::unordered_map< std::string , unsigned long > first_vec , second_vec;
    
    std::thread t1(&word_to_vec::word_vec , _T , std::ref(first_vec) );
    std::thread t2(&word_to_vec::word_vec , _X , std::ref(second_vec) );
    t1.join();
    t2.join();
    
    std::thread t3( [&](/*std::unordered_map< std::string , unsigned long >& first_vec*/)
    {
    for( auto i = first_vec.begin(); i!=first_vec.end(); ++i )
    {
        if( second_vec.find( i->first ) == second_vec.end() )
        {
            second_vec[ i->first ] = constant < 0 >::val;
        }
    }
    } /*, std::ref(first_vec) */);
    std::thread t4([&](/*std::unordered_map< std::string , unsigned long >& first_vec*/)
    {
    for( auto j = second_vec.begin(); j != second_vec.end(); ++j)
    {
        if( first_vec.find( j->first ) == first_vec.end() )
        {
            first_vec[ j->first ] = constant < 0 >::val;
        }
    }
    } /*, std::ref(first_vec) */);
    t3.join();
    t4.join();
    std::unordered_map< std::string , std::pair< long double, long double > > vec;
    for( auto i = first_vec.begin(); i != first_vec.end(); ++i )
    {
        vec[ i->first ] = std::make_pair( i->second , second_vec[ i->first ] );
    }

    return vec;
}
}
#undef RAD_1
#undef LOG_10