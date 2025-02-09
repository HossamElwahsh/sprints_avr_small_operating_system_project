/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *-------------------------------------------------------------------------------------------------------------------
 *
 *		   @Date:  	5:34 PM Monday, May 15, 2023
 *		   @File:  	timer_cfg.h         
 *		 @Module:  	Timer
 *		 @Author:	Ahmed Hesham
 *  @Description:  	Pre-configuration file for Timer module     
 *  
 *********************************************************************************************************************/
#ifndef TIMER_CFG_H
#define TIMER_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "timer_interface.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*************************_SYSTEM_OSCILLARTOR_CLOCK_FREQUENCY_*************************/
/*
 *	Enter microcontrolers frequency in Hz writing UL besides it
 */
#define F_CPU							8000000UL

/*************************_NUMBER_OF_TIMERS_USED_*************************/
/*
 *	number of timers used
 */

#define NUMBER_OF_TIMERS_USED			1

 
#endif  /* TIMERCFG_H */
/**********************************************************************************************************************
 *  END OF FILE: timer_cfg.h
 *********************************************************************************************************************/
