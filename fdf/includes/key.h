/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:37:54 by mchan             #+#    #+#             */
/*   Updated: 2019/10/17 22:35:51 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

/*
**	Virtual keycodes as found in:
**	https://developer.apple.com/library/archive/documentation/mac/pdf
**	/MacintoshToolboxEssentials.pdf
**
**	These constants are the virtual keycodes defined originally in
**	Inside Mac Volume V, pg. V-191. They identify physical keys on a
**	keyboard. Those constants with "ANSI" in the name are labeled
**	according to the key position on an ANSI-standard US keyboard.
**	For example, kVK_ANSI_A indicates the virtual keycode for the key
**	with the letter 'A' in the US keyboard layout. Other keyboard
**	layouts may have the 'A' key label on a different physical key;
**	in this case, pressing 'A' will generate a different virtual
**	keycode.
*/

# define KEY_ANSI_A					(0x00)
# define KEY_ANSI_S 				(0x01)
# define KEY_ANSI_D 				(0x02)
# define KEY_ANSI_F 				(0x03)
# define KEY_ANSI_H 				(0x04)
# define KEY_ANSI_G 				(0x05)
# define KEY_ANSI_Z 				(0x06)
# define KEY_ANSI_X 				(0x07)
# define KEY_ANSI_C 				(0x08)
# define KEY_ANSI_V 				(0x09)
# define KEY_ANSI_B 				(0x0B)
# define KEY_ANSI_Q 				(0x0C)
# define KEY_ANSI_W 				(0x0D)
# define KEY_ANSI_E 				(0x0E)
# define KEY_ANSI_R 				(0x0F)
# define KEY_ANSI_Y 				(0x10)
# define KEY_ANSI_T 				(0x11)
# define KEY_ANSI_1 				(0x12)
# define KEY_ANSI_2 				(0x13)
# define KEY_ANSI_3 				(0x14)
# define KEY_ANSI_4 				(0x15)
# define KEY_ANSI_6 				(0x16)
# define KEY_ANSI_5 				(0x17)
# define KEY_ANSI_EQUALS			(0x18)
# define KEY_ANSI_9					(0x19)
# define KEY_ANSI_7					(0x1A)
# define KEY_ANSI_MINUS				(0x1B)
# define KEY_ANSI_8					(0x1C)
# define KEY_ANSI_0					(0x1D)
# define KEY_ANSI_CLOSEBRACKET		(0x1E)
# define KEY_ANSI_O					(0x1F)
# define KEY_ANSI_U					(0x20)
# define KEY_ANSI_OPENBRACKET		(0x21)
# define KEY_ANSI_I					(0x22)
# define KEY_ANSI_P					(0x23)
# define KEY_ANSI_L					(0x25)
# define KEY_ANSI_J					(0x26)
# define KEY_ANSI_DOUBLEQUOTE		(0x27)
# define KEY_ANSI_K					(0x28)
# define KEY_ANSI_SEMICOLON			(0x29)
# define KEY_ANSI_BACKSLASH			(0x2A)
# define KEY_ANSI_COMMA				(0x2B)
# define KEY_ANSI_FORWARDSLASH		(0x2C)
# define KEY_ANSI_N					(0x2D)
# define KEY_ANSI_M					(0x2E)
# define KEY_ANSI_PERIOD			(0x2F)
# define KEY_ANSI_TILDE				(0x32)
# define KEY_ANSI_KEYPAD_DECIMAL	(0x41)
# define KEY_ANSI_KEYPAD_MULTIPLY	(0x43)
# define KEY_ANSI_KEYPAD_PLUS		(0x45)
# define KEY_ANSI_KEYPAD_CLEAR		(0x47)
# define KEY_ANSI_KEYPAD_DIVIDE		(0x4B)
# define KEY_ANSI_KEYPAD_ENTER		(0x4C)
# define KEY_ANSI_KEYPAD_MINUS		(0x4E)
# define KEY_ANSI_KEYPAD_EQUALS		(0x51)
# define KEY_ANSI_KEYPAD_0			(0x52)
# define KEY_ANSI_KEYPAD_1			(0x53)
# define KEY_ANSI_KEYPAD_2			(0x54)
# define KEY_ANSI_KEYPAD_3			(0x55)
# define KEY_ANSI_KEYPAD_4			(0x56)
# define KEY_ANSI_KEYPAD_5			(0x57)
# define KEY_ANSI_KEYPAD_6			(0x58)
# define KEY_ANSI_KEYPAD_7			(0x59)
# define KEY_ANSI_KEYPAD_8			(0x5B)
# define KEY_ANSI_KEYPAD_9			(0x5C)

/*
**	Those constants without "ANSI" in the name are labeled independently
**	of a particular keyboard layout.
*/

# define KEY_RETURN					(0x24)
# define KEY_TAB					(0x30)
# define KEY_SPACE					(0x31)
# define KEY_BACKSPACE				(0x33)
# define KEY_ESCAPE					(0x35)
# define KEY_COMMAND				(0x37)
# define KEY_SHIFT					(0x38)
# define KEY_CAPSLOCK				(0x39)
# define KEY_OPTION					(0x3A)
# define KEY_CONTROL				(0x3B)
# define KEY_RIGHT_SHIFT			(0x3C)
# define KEY_RIGHT_OPTION			(0x3D)
# define KEY_RIGHT_CONTROL			(0x3E)
# define KEY_FUNCTION				(0x3F)
# define KEY_F17					(0x40)
# define KEY_VOLUME_UP				(0x48)
# define KEY_VOLUME_DOWN			(0x49)
# define KEY_MUTE					(0x4A)
# define KEY_F18					(0x4F)
# define KEY_F19					(0x50)
# define KEY_F20					(0x5A)
# define KEY_F5						(0x60)
# define KEY_F6						(0x61)
# define KEY_F7						(0x62)
# define KEY_F3						(0x63)
# define KEY_F8						(0x64)
# define KEY_F9						(0x65)
# define KEY_F11					(0x67)
# define KEY_F13					(0x69)
# define KEY_F16					(0x6A)
# define KEY_F14					(0x6B)
# define KEY_F10					(0x6D)
# define KEY_F12					(0x6F)
# define KEY_F15					(0x71)
# define KEY_HELP					(0x72)
# define KEY_HOME					(0x73)
# define KEY_PAGE_UP				(0x74)
# define KEY_DELETE					(0x75)
# define KEY_F4						(0x76)
# define KEY_END					(0x77)
# define KEY_F2						(0x78)
# define KEY_PAGE_DOWN				(0x79)
# define KEY_F1						(0x7A)
# define KEY_LEFT_ARROW				(0x7B)
# define KEY_RIGHT_ARROW			(0x7C)
# define KEY_DOWN_ARROW				(0x7D)
# define KEY_UP_ARROW				(0x7E)

#endif
