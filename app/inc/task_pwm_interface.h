#ifndef TASK_INC_TASK_PWM_INTERFACE_H_
#define TASK_INC_TASK_PWM_INTERFACE_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/

/********************** macros ***********************************************/

/********************** typedef **********************************************/

/********************** external data declaration ****************************/

/********************** external functions declaration ***********************/
extern void init_queue_event_task_pwm(void);
extern void put_event_task_pwm(uint16_t valor);
extern uint16_t get_event_task_pwm(void);
extern bool any_event_task_pwm(void);

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* TASK_INC_TASK_SYSTEM_INTERFACE_H_ */

/********************** end of file ******************************************/
