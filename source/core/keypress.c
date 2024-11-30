#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include "keypress.h"
#include "../entity/entity.h"

void init_keystrokes(void)
{
    Display* display;
    Window window;
    XEvent event;
    int s;

    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
	exit(1);
    }

    s = DefaultScreen(display);

    window = XCreateSimpleWindow(display, RootWindow(display, s), 10, 10
    , 200, 200, 1, BlackPixel(display, s), WhitePixel(display, s));

    XSelectInput(display, window, KeyPressMask | KeyReleaseMask);

    XMapWindow(display, window);

    while(1)
    {
	XNextEvent(display, &event);

	if (event.type == KeyPress)
	{
	    KeySym keysym = XLookupKeysym(&event.xkey, 0); // get keysym code

	    switch(keysym)
	    {
		case XK_Left:
		    ent.pos = move_entity()
		    break;

		case XK_Right:
		    break;

		case XK_Up:
		    break;

		case XK_Down:
		    break;
	    }
	}
    }
}
