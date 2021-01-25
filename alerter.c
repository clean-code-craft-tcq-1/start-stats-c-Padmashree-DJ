/*
 * emailalerter.c
 *
 *  Created on: Jan 24, 2021
 *      Author: JPD5KOR
 */
#include "alerter.h"

alerter_funcptr emailAlerter()
{
    emailAlertCallCount++;
}

alerter_funcptr ledAlerter()
{
    ledAlertCallCount++;
}


