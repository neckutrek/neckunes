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

 #ifndef __NECKUNES_MAIN_LOOP_CALLBACK_H__
 #define __NECKUNES_MAIN_LOOP_CALLBACK_H__

namespace neckunes
{

class MainLoopCallback
{
public:
   virtual ~MainLoopCallback() = default;
   virtual void tick() = 0;
};

} // namespace neckunes

 #endif