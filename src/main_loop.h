/**
 * NeckuNES
 * Copyright (C) 2019 Marcus Johansson
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

 #ifndef __NECKUNES_MAIN_LOOP_H__
 #define __NECKUNES_MAIN_LOOP_H__

#include "main_loop_callback.h"

namespace neckunes
{

template<class CallbackT>
class MainLoop
{
public:
               MainLoop();

   void        start();

private:

   CallbackT         _callback;

   const int         _n_ms_per_tick = getNumMsPerTick();

   constexpr int     getNumMsPerTick()
   {
      return (int)( 1.0 / ( 1.79 ) + 0.5 );
   }
   
};

} // namespace neckunes

#include "main_loop.hpp"

 #endif