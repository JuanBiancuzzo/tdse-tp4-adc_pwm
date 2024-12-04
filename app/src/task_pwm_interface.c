#include "main.h"

/* Demo includes. */
#include "logger.h"
#include "dwt.h"

/* Application & Tasks includes. */
#include "board.h"
#include "app.h"

/********************** macros and definitions *******************************/
#define EVENT_UNDEFINED	(255)
#define MAX_EVENTS		(255)

/********************** internal data declaration ****************************/

/********************** internal functions declaration ***********************/

/********************** internal data definition *****************************/
struct
{
	uint32_t	head;
	uint32_t	tail;
	uint32_t	count;
	uint16_t	queue[MAX_EVENTS];
} queue_task_a;

/********************** external data declaration ****************************/

/********************** external functions definition ************************/
void init_queue_event_task_pwm(void) {
	uint32_t i;

	queue_task_a.head = 0;
	queue_task_a.tail = 0;
	queue_task_a.count = 0;

	for (i = 0; i < MAX_EVENTS; i++)
		queue_task_a.queue[i] = EVENT_UNDEFINED;
}

void put_event_task_pwm(uint16_t valor) {
	queue_task_a.count++;
	queue_task_a.queue[queue_task_a.head++] = valor;

	if (MAX_EVENTS == queue_task_a.head)
		queue_task_a.head = 0;
}

uint16_t get_event_task_pwm(void) {
	uint16_t valor;

	queue_task_a.count--;
	valor = queue_task_a.queue[queue_task_a.tail];
	queue_task_a.queue[queue_task_a.tail++] = EVENT_UNDEFINED;

	if (MAX_EVENTS == queue_task_a.tail)
		queue_task_a.tail = 0;

	return valor;
}

bool any_event_task_pwm(void) {
  return (queue_task_a.head != queue_task_a.tail);
}

/********************** end of file ******************************************/
