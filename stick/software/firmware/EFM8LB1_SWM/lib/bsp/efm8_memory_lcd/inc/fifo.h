//-----------------------------------------------------------------------------
// Fifo.h
//-----------------------------------------------------------------------------
// Copyright 2008-2014 Silicon Laboratories, Inc.
// http://www.silabs.com
//
// Program Description:
//
// Macros to allocate and access a FIFO
//
// Usage:
// - To define all FIFO functions (push, pop, size, clear) and required global
// variables, use FIFO_DEFINE_ALL().
// - To define individual FIFO function, use FIFO_DEFINE_PUSH(), FIFO_DEFINE_POP(),
// FIFO_DEFINE_SIZE(), or FIFO_DEFINE_CLEAR().
// - Global variables for the FIFO must always be defined using FIFO_DEFINE_GLOBAL()
// or FIFO_DEFINE_ALL().
// - To define prototypes for all FIFO functions (push, pop, size, clear), use
// FIFO_DEFINE_ALL_PROTOTYPES().
// - To define individual FIFO function prototypes, use FIFO_DEFINE_PUSH_PROTOTYPE(),
// FIFO_DEFINE_POP_PROTOTYPE(), FIFO_DEFINE_SIZE_PROTOTYPE(), or
// FIFO_DEFINE_CLEAR_PROTOTYPE()
//
// Warning: FIFO functions may not be interrupt safe!  Disable any interrupts that
// can call a FIFO function before calling the function from the foreground,
// otherwise FIFO variables will become corrupted!
// -or-
// Use the FIFO macro ie_sfr and ie_mask parameters to automatically
// disable and then enable the specified interrupt using the specified mask.
//
//
// How To Test:    See Readme.txt
//
// Target:         
//
// Tool chain:     Keil C51 7.50 / Keil EVAL C51
//                 Silicon Laboratories IDE version 2.6
// Command Line:   See Readme.txt
// Project Name:   F380_USB0_Audio
//
// Release 1.0
//    -Initial Revision (CM)
//    -16 DEC 2013
//

#ifndef _FIFO_H_
#define _FIFO_H_

//-----------------------------------------------------------------------------
// FIFO_DEFINE_GLOBALS
//-----------------------------------------------------------------------------
// Allocate all global variables needed to implement a FIFO
//
// name - The name of the FIFO (i.e. Tx)
// elementDataType - data type for the elements in the FIFO (i.e. uint8_t)
// indexDataType - data type for the head/tail indices (i.e. uint16_t)
// mspace - The memory space that the FIFO buffer will occupy (i.e. SEG_XDATA)
// capacity - The maximum size of the FIFO buffer in number of elements (i.e. 1024)
// ie_sfr - The interrupt enable SFR name (i.e. IE, EIE1)
// ie_mask - The interrupt enable mask used to disable/enable interrupts during
// critical sections of FIFO variable modifications (i.e. 0x80 for IE would set EA
// to 0 at the beginning of FIFO functions and set EA = 1 before returning from
// FIFO functions)
//
// NOTE: FIFO_DEFINE(...) must not be followed by a semicolon (;)
//-----------------------------------------------------------------------------
#define FIFO_DEFINE_GLOBALS(name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask) \
   SI_SEGMENT_VARIABLE(name##_Buffer[(capacity)], elementDataType, mspace); \
   indexDataType name##_Count = 0; \
   indexDataType name##_Head = 0; \
   indexDataType name##_Tail = 0;

//-----------------------------------------------------------------------------
// FIFO_DEFINE_PUSH
//-----------------------------------------------------------------------------
// Define the FIFO push function
//
// name - The name of the FIFO (i.e. Tx)
// elementDataType - data type for the elements in the FIFO (i.e. uint8_t)
// indexDataType - data type for the head/tail indices (i.e. uint16_t)
// mspace - The memory space that the FIFO buffer will occupy (i.e. SEG_XDATA)
// capacity - The maximum size of the FIFO buffer in number of elements (i.e. 1024)
// ie_sfr - The interrupt enable SFR name (i.e. IE, EIE1)
// ie_mask - The interrupt enable mask used to disable/enable interrupts during
// critical sections of FIFO variable modifications (i.e. 0x80 for IE would set EA
// to 0 at the beginning of FIFO functions and set EA = 1 before returning from
// FIFO functions)
//
// returns - 1 if success, 0 if FIFO is full
//
// NOTE: FIFO_DEFINE(...) must not be followed by a semicolon (;)
//
// WARNING: This macro disables and then re-enables the specified interrupt enable
// mask! This may not be appropriate for all firmware applications.
//-----------------------------------------------------------------------------
#define FIFO_DEFINE_PUSH(name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask) \
   uint8_t name##_Push(elementDataType value) \
   { \
      ie_sfr &= ~ie_mask; \
      if (name##_Count < (capacity)) \
      { \
         name##_Buffer[name##_Head] = value; \
         name##_Head = (name##_Head + 1) % (capacity); \
         name##_Count++; \
         ie_sfr |= ie_mask; \
         return 1; \
      } \
      ie_sfr |= ie_mask; \
      return 0; \
   }

//-----------------------------------------------------------------------------
// FIFO_DEFINE_POP
//-----------------------------------------------------------------------------
// Define the FIFO pop function
//
// name - The name of the FIFO (i.e. Tx)
// elementDataType - data type for the elements in the FIFO (i.e. uint8_t)
// indexDataType - data type for the head/tail indices (i.e. uint16_t)
// mspace - The memory space that the FIFO buffer will occupy (i.e. SEG_XDATA)
// capacity - The maximum size of the FIFO buffer in number of elements (i.e. 1024)
// ie_sfr - The interrupt enable SFR name (i.e. IE, EIE1)
// ie_mask - The interrupt enable mask used to disable/enable interrupts during
// critical sections of FIFO variable modifications (i.e. 0x80 for IE would set EA
// to 0 at the beginning of FIFO functions and set EA = 1 before returning from
// FIFO functions)
//
// returns - 1 if success, 0 if FIFO is empty
//
// NOTE: FIFO_DEFINE(...) must not be followed by a semicolon (;)
//
// WARNING: This macro disables and then re-enables the specified interrupt enable
// mask! This may not be appropriate for all firmware applications.
//-----------------------------------------------------------------------------
#define FIFO_DEFINE_POP(name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask) \
   uint8_t name##_Pop(elementDataType* value) \
   { \
      ie_sfr &= ~ie_mask; \
      if (name##_Count > 0) \
      { \
         *value = name##_Buffer[name##_Tail]; \
         name##_Tail = (name##_Tail + 1) % (capacity); \
         name##_Count--; \
         ie_sfr |= ie_mask; \
         return 1; \
      } \
      ie_sfr |= ie_mask; \
      return 0; \
   }

//-----------------------------------------------------------------------------
// FIFO_DEFINE_SIZE
//-----------------------------------------------------------------------------
// Define the FIFO size function
//
// name - The name of the FIFO (i.e. Tx)
// elementDataType - data type for the elements in the FIFO (i.e. uint8_t)
// indexDataType - data type for the head/tail indices (i.e. uint16_t)
// mspace - The memory space that the FIFO buffer will occupy (i.e. SEG_XDATA)
// capacity - The maximum size of the FIFO buffer in number of elements (i.e. 1024)
// ie_sfr - The interrupt enable SFR name (i.e. IE, EIE1)
// ie_mask - The interrupt enable mask used to disable/enable interrupts during
// critical sections of FIFO variable modifications (i.e. 0x80 for IE would set EA
// to 0 at the beginning of FIFO functions and set EA = 1 before returning from
// FIFO functions)
//
// returns - the current size of the FIFO
//
// NOTE: FIFO_DEFINE(...) must not be followed by a semicolon (;)
//
// WARNING: This macro disables and then re-enables the specified interrupt enable
// mask! This may not be appropriate for all firmware applications.
//-----------------------------------------------------------------------------
#define FIFO_DEFINE_SIZE(name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask) \
   indexDataType name##_Size() \
   { \
      indexDataType size; \
      ie_sfr &= ~ie_mask; \
      size = name##_Count; \
      ie_sfr |= ie_mask; \
      return size; \
   }

//-----------------------------------------------------------------------------
// FIFO_DEFINE_CLEAR
//-----------------------------------------------------------------------------
// Clear the FIFO
//
// name - The name of the FIFO (i.e. Tx)
// elementDataType - data type for the elements in the FIFO (i.e. uint8_t)
// indexDataType - data type for the head/tail indices (i.e. uint16_t)
// mspace - The memory space that the FIFO buffer will occupy (i.e. SEG_XDATA)
// capacity - The maximum size of the FIFO buffer in number of elements (i.e. 1024)
// ie_sfr - The interrupt enable SFR name (i.e. IE, EIE1)
// ie_mask - The interrupt enable mask used to disable/enable interrupts during
// critical sections of FIFO variable modifications (i.e. 0x80 for IE would set EA
// to 0 at the beginning of FIFO functions and set EA = 1 before returning from
// FIFO functions)
//
// NOTE: FIFO_DEFINE(...) must not be followed by a semicolon (;)
//
// WARNING: This macro disables and then re-enables the specified interrupt enable
// mask! This may not be appropriate for all firmware applications.
//-----------------------------------------------------------------------------
#define FIFO_DEFINE_CLEAR(name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask) \
   void name##_Clear() \
   { \
      ie_sfr &= ~ie_mask; \
      name##_Count = 0; \
      name##_Head = 0; \
      name##_Tail = 0; \
      ie_sfr |= ie_mask; \
   }

//-----------------------------------------------------------------------------
// FIFO_DEFINE_ALL
//-----------------------------------------------------------------------------
// Allocate all global variables and define functions needed to access a FIFO
//
// name - The name of the FIFO (i.e. Tx)
// elementDataType - data type for the elements in the FIFO (i.e. uint8_t)
// indexDataType - data type for the head/tail indices (i.e. uint16_t)
// mspace - The memory space that the FIFO buffer will occupy (i.e. SEG_XDATA)
// capacity - The maximum size of the FIFO buffer in number of elements (i.e. 1024)
// ie_sfr - The interrupt enable SFR name (i.e. IE, EIE1)
// ie_mask - The interrupt enable mask used to disable/enable interrupts during
// critical sections of FIFO variable modifications (i.e. 0x80 for IE would set EA
// to 0 at the beginning of FIFO functions and set EA = 1 before returning from
// FIFO functions)
//
// NOTE: FIFO_DEFINE(...) must not be followed by a semicolon (;)
//
// WARNING: This macro disables and then re-enables the specified interrupt enable
// mask! This may not be appropriate for all firmware applications.
//-----------------------------------------------------------------------------
#define FIFO_DEFINE_ALL(name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask) \
   FIFO_DEFINE_GLOBALS (name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask) \
   FIFO_DEFINE_PUSH    (name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask) \
   FIFO_DEFINE_POP     (name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask) \
   FIFO_DEFINE_SIZE    (name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask) \
   FIFO_DEFINE_CLEAR   (name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask)

#define FIFO_DEFINE_PUSH_POP(name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask) \
   FIFO_DEFINE_GLOBALS      (name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask) \
   FIFO_DEFINE_PUSH         (name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask) \
   FIFO_DEFINE_POP          (name, elementDataType, indexDataType, mspace, capacity, ie_sfr, ie_mask)

//-----------------------------------------------------------------------------
// FIFO_DEFINE_PUSH_PROTOTYPE
//-----------------------------------------------------------------------------
// Define FIFO_PUSH function prototype
//
// name - The name of the FIFO (i.e. Tx)
// elementDataType - data type for the elements in the FIFO (i.e. uint8_t)
// indexDataType - data type for the head/tail indices (i.e. uint16_t)
//
// NOTE: FIFO_DEFINE_PROTOTYPE(...) must not be followed by a semicolon (;)
//-----------------------------------------------------------------------------
#define FIFO_DEFINE_PUSH_PROTOTYPE(name, elementDataType, indexDataType) \
   uint8_t name##_Push(elementDataType value);

//-----------------------------------------------------------------------------
// FIFO_DEFINE_POP_PROTOTYPE
//-----------------------------------------------------------------------------
// Define FIFO_POP function prototype
//
// name - The name of the FIFO (i.e. Tx)
// elementDataType - data type for the elements in the FIFO (i.e. uint8_t)
// indexDataType - data type for the head/tail indices (i.e. uint16_t)
//
// NOTE: FIFO_DEFINE_PROTOTYPE(...) must not be followed by a semicolon (;)
//-----------------------------------------------------------------------------
#define FIFO_DEFINE_POP_PROTOTYPE(name, elementDataType, indexDataType) \
   uint8_t name##_Pop(elementDataType* value);

//-----------------------------------------------------------------------------
// FIFO_DEFINE_SIZE_PROTOTYPE
//-----------------------------------------------------------------------------
// Define FIFO_SIZE function prototype
//
// name - The name of the FIFO (i.e. Tx)
// elementDataType - data type for the elements in the FIFO (i.e. uint8_t)
// indexDataType - data type for the head/tail indices (i.e. uint16_t)
//
// NOTE: FIFO_DEFINE_PROTOTYPE(...) must not be followed by a semicolon (;)
//-----------------------------------------------------------------------------
#define FIFO_DEFINE_SIZE_PROTOTYPE(name, elementDataType, indexDataType) \
   indexDataType name##_Size();

//-----------------------------------------------------------------------------
// FIFO_DEFINE_CLEAR_PROTOTYPE
//-----------------------------------------------------------------------------
// Define FIFO_CLEAR function prototype
//
// name - The name of the FIFO (i.e. Tx)
// elementDataType - data type for the elements in the FIFO (i.e. uint8_t)
// indexDataType - data type for the head/tail indices (i.e. uint16_t)
//
// NOTE: FIFO_DEFINE_PROTOTYPE(...) must not be followed by a semicolon (;)
//-----------------------------------------------------------------------------
#define FIFO_DEFINE_CLEAR_PROTOTYPE(name, elementDataType, indexDataType) \
   void name##_Clear();

//-----------------------------------------------------------------------------
// FIFO_DEFINE_ALL_PROTOTYPES
//-----------------------------------------------------------------------------
// Define prototypes for functions needed to access a FIFO
//
// name - The name of the FIFO (i.e. Tx)
// elementDataType - data type for the elements in the FIFO (i.e. uint8_t)
// indexDataType - data type for the head/tail indices (i.e. uint16_t)
//
// NOTE: FIFO_DEFINE_ALL_PROTOTYPES(...) must not be followed by a semicolon (;)
//-----------------------------------------------------------------------------
#define FIFO_DEFINE_ALL_PROTOTYPES(name, elementDataType, indexDataType) \
   FIFO_DEFINE_PUSH_PROTOTYPE     (name, elementDataType, indexDataType) \
   FIFO_DEFINE_POP_PROTOTYPE      (name, elementDataType, indexDataType) \
   FIFO_DEFINE_SIZE_PROTOTYPE     (name, elementDataType, indexDataType) \
   FIFO_DEFINE_CLEAR_PROTOTYPE    (name, elementDataType, indexDataType)

//-----------------------------------------------------------------------------
// FIFO_PUSH
//-----------------------------------------------------------------------------
// Push an element onto the named FIFO
//
// name - The name of the FIFO (i.e. Tx)
// value - The value of the element to push onto the FIFO
//
// returns - 1 if successful, 0 if FIFO is full
//-----------------------------------------------------------------------------
#define FIFO_PUSH(name, value)      name##_Push((value))

//-----------------------------------------------------------------------------
// FIFO_POP
//-----------------------------------------------------------------------------
// Pop an element off the named FIFO
//
// name - The name of the FIFO (i.e. Tx)
// value - An element type variable that will return the value removed from the FIFO (i.e. &value)
//
// returns - 1 if successful, 0 if FIFO isempty
//-----------------------------------------------------------------------------
#define FIFO_POP(name, value)       name##_Pop((value))

//-----------------------------------------------------------------------------
// FIFO_SIZE
//-----------------------------------------------------------------------------
// Return the size of the named FIFO
//
// name - The name of the FIFO (i.e. Tx)
//-----------------------------------------------------------------------------
#define FIFO_SIZE(name)             name##_Size()

//-----------------------------------------------------------------------------
// FIFO_CLEAR
//-----------------------------------------------------------------------------
// Clear the FIFO
//
// name - The name of the FIFO (i.e. Tx)
//-----------------------------------------------------------------------------
#define FIFO_CLEAR(name)             name##_Clear()

#endif //_FIFO_H_
