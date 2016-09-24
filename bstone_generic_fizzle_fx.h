/*
BStone: A Source port of
Blake Stone: Aliens of Gold and Blake Stone: Planet Strike

Copyright (c) 1992-2013 Apogee Entertainment, LLC
Copyright (c) 2013-2015 Boris I. Bendovsky (bibendovsky@hotmail.com)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the
Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/


//
// Generic fizzle effect.
//


#include <cstdint>
#include "bstone_fizzle_fx.h"


namespace bstone
{


class GenericFizzleFX :
    public FizzleFX
{
public:
    GenericFizzleFX(
        uint8_t plot_color,
        bool is_transparent);

    GenericFizzleFX(
        const GenericFizzleFX& that) = delete;

    GenericFizzleFX& operator=(
        const GenericFizzleFX& that) = delete;

    ~GenericFizzleFX() override;


    // Initializes the effect.
    void initialize() override;


protected:
    // Clean-ups the effect.
    void uninitialize() override;

    // Returns true if the effect can be interrupted.
    bool is_abortable() const override;

    // Returns total frame count.
    int get_frame_count() const override;

    // Returns vertical offset of the effect beginning.
    int get_y() const override;

    // Returns total height of the effect.
    int get_height() const override;

    // Performs operation on one pixel.
    void plot(
        int x,
        int y) override;

    // Presents the final stage of the effect.
    void skip_to_the_end() override;


private:
    uint8_t plot_color_;
    bool is_transparent_;
    int y_offset_;
    int height_;
}; // GenericFizzleFX


} // bstone
