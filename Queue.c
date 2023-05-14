#include <stdio.h>
#include <string.h>

#define QUEUE_SIZE 5

typedef struct {
    int sit_number;
    char passenger_name[20];
    char from[20];
    char to[20];
} Ticket;

typedef struct {
    Ticket tickets[QUEUE_SIZE];
    int tail, head;
} TicketQueue;

void create_ticket(TicketQueue *queue, int sit_number, char passenger_name[], char from[], char to[]) {
    if ((queue->tail + 1) % QUEUE_SIZE == queue->head) {
        printf("Ticket queue is full!\n");
        return;
    }

    Ticket *ticket = &queue->tickets[queue->tail];
    ticket->sit_number = sit_number;
    strcpy(ticket->passenger_name, passenger_name);
    strcpy(ticket->from, from);
    strcpy(ticket->to, to);
    queue->tail = (queue->tail + 1) % QUEUE_SIZE;
}

int ticket_output(TicketQueue *queue) {
    if (queue->tail == queue->head) {
        printf("Queue is empty!\n");
        return -1;
    }

    Ticket *ticket = &queue->tickets[queue->head];
    printf("Ticket number: %d\n", ticket->sit_number);
    printf("Passenger name: %s\n", ticket->passenger_name);
    printf("From: %s\n", ticket->from);
    printf("To: %s\n", ticket->to);
    queue->head = (queue->head + 1) % QUEUE_SIZE;
    return ticket->sit_number;
}

int main() {
    TicketQueue queue;
    queue.tail = 0;
    queue.head = 0;

    create_ticket(&queue, 10, "Ragib", "kishorgonj", "Dhaka");
    create_ticket(&queue, 20, "Shajidul Islam", "kishorgonj", "Dhaka");
    create_ticket(&queue, 30, "Shaimul", "kishorgonj", "Dhaka");
    create_ticket(&queue, 40, "Rahat Khan", "kishorgonj", "Dhaka");
    create_ticket(&queue, 50, "Tushar Molla", "kishorgonj", "Dhaka");
    create_ticket(&queue, 60, "Shahariar", "kishorgonj", "Dhaka");

    printf("Printing Ticket Details: \n");
    while (queue.head != queue.tail) {
        int item = ticket_output(&queue);
        printf("Ticket number %d has been processed.\n", item);
    }
    printf("Ticket queue is empty! (sold out)\n");
}
