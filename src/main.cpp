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

#include <iostream>

#include "main_loop.hpp"

class CB : public neckunes::MainLoopCallback
{
public:
   ~CB() = default;
   void tick()
   {
      std::cout << ". ";
      std::cout.flush();
   }
};

int main(int argc, char** argv)
{
   neckunes::MainLoop<CB> mainLoop;
   mainLoop.setTickSpeed( 4 );

   mainLoop.start();

   
   return 0;
}