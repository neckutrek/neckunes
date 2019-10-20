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

 //#include "main_loop.h"

#include "main_loop_callback.h"

 #include <chrono>
 #include <utility>
 #include <type_traits>
 #include <thread>

namespace neckunes
{

template<class CallbackT>
MainLoop<CallbackT>::MainLoop()
{
   static_assert( std::is_base_of<MainLoopCallback, CallbackT>::value );
   _callback = CallbackT();
}

template<class CallbackT>
void MainLoop<CallbackT>::start()
{
   const std::chrono::microseconds n_ms_per_tick( getNumMsPerTick() );

   bool run = true;
   while ( run )
   {
      auto begin_time = std::chrono::high_resolution_clock::now();

      _callback.tick();

      auto end_time = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>
         (end_time - begin_time);

      if ( duration < n_ms_per_tick )
      {
         std::chrono::microseconds sleeptime = n_ms_per_tick - duration;
         std::this_thread::sleep_for( sleeptime );
      }
   }

}

} // namespace neckunes