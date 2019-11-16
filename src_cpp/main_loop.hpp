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

#include <chrono>
#include <utility>
#include <type_traits>
#include <thread>

namespace neckunes
{

class MainLoopCallback
{
public:
   virtual ~MainLoopCallback() = default;
   virtual void tick() = 0;
};

template<class CallbackT>
class MainLoop
{
public:
               MainLoop();

   inline void setTickSpeed(double hertz)
   {
      _nanosecsPerTick = hertzToNanosecs( hertz );
   }

   void        start();

private:

   CallbackT         _callback;

   int               _nanosecsPerTick = hertzToNanosecs( 1'790'000'000 );

   constexpr int     hertzToNanosecs(double hertz)
   {
      return (int)( 1000000000.0 / hertz + 0.5 );
   }
   
};

template<class CallbackT>
MainLoop<CallbackT>::MainLoop()
{
   static_assert( std::is_base_of<MainLoopCallback, CallbackT>::value );
   _callback = CallbackT();
}

template<class CallbackT>
void MainLoop<CallbackT>::start()
{
   const std::chrono::nanoseconds nanosecsPerTick( _nanosecsPerTick );

   bool run = true;
   while ( run )
   {
      auto begin_time = std::chrono::high_resolution_clock::now();

      _callback.tick();

      auto end_time = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>
         (end_time - begin_time);

      if ( duration < nanosecsPerTick )
      {
         std::this_thread::sleep_for( nanosecsPerTick - duration );
      }
   }

}

} // namespace neckunes