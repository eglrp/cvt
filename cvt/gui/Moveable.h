/*
   The MIT License (MIT)

   Copyright (c) 2011 - 2013, Philipp Heise and Sebastian Klose
   Copyright (c) 2016, BMW Car IT GmbH, Philipp Heise (philipp.heise@bmw.de)

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
*/
#ifndef CVT_MOVEABLE_H
#define CVT_MOVEABLE_H

#include <cvt/gui/WidgetContainer.h>
#include <cvt/gui/ToggleButton.h>
#include <cvt/util/String.h>

namespace cvt {
    class Moveable : public WidgetContainer
    {
        public:
            Moveable( Widget* child );
            ~Moveable();

            Widget* child();
            void setTitle( const String& title );

            bool collapsed() const;

        private:
            void paintEvent( PaintEvent& ev, GFX& g );
            void resizeEvent( ResizeEvent& ev );
            void mousePressEvent( MousePressEvent& ev );
            void mouseMoveEvent( MouseMoveEvent& ev );
            void mouseReleaseEvent( MouseReleaseEvent& ev );

            void onToggle( ToggleButton* button );

            Widget* _child;
            Widget* _activeWidget;
            int _activeMode;
            int _lx, _ly;
            int _oldheight;
            String _title;
            ToggleButton _togglebutton;
            Delegate<void ( ToggleButton* )> _onToggleDelegate;
    };

    inline Widget* Moveable::child()
    {
        return _child;
    }

    inline bool Moveable::collapsed() const
    {
        return _togglebutton.state();
    }
}

#endif
