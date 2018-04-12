#ifndef _INPUT_H
#define _INPUT_H

#define MOUSE_REL	0x00		/* 8bit deltas - may need 16 ? */
#define MOUSE_ABS	0x10		/* 16bit x 16bit virtual coords */
#define STICK_DIGITAL	0x20		/* UDLR + buttons byte */
#define 	STICK_DIGITAL_U	0x80
#define		STICK_DIGITAL_D 0x40
#define		STICK_DIGITAL_L	0x20
#define		STICK_DIGITAL_R	0x10
#define STICK_ANALOG	0x30		/* 16bit signed X / Y, sign */
#define KEYPRESS_CODE	0x40		/* Followed by keycode byte. Button
                                           bits show u/d and 3 spare bits */
#define		KEYPRESS_DOWN	0x00
#define		KEYPRESS_UP	0x01

#define BUTTONS(x)	((x)&0x0F)	/* 1-4 buttons */


#define INPUT_GRABKB	0x0520
#define		INPUT_GRAB_NONE		0	/* No grab */
#define		INPUT_GRAB_META		1	/* Special keys only */
#define		INPUT_GRAB_TYPED	2	/* Typed input */
#define		INPUT_GRAB_ALL		3	/* Up and down events */

/*
 *	Input device methods
 */
extern int inputdev_read(uint8_t flag);
extern int inputdev_write(uint8_t flag);
extern int inputdev_ioctl(uarg_t request, char *data);
extern int inputdev_close(void);

/*
 *	Exposed for keyboard drivers
 */
extern uint8_t keyboard_grab;

/*
 *	Platform methods for input device if present
 */
extern int platform_input_read(uint8_t *);
extern void platform_input_wait(void);
extern int platform_input_write(uint8_t);
extern uint8_t platform_input_init(void);

#endif
