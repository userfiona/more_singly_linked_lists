/**
 * print_listint_safe - prints a list but safely
 * @head: the head node. pointer
 *
 * Description: dont wanna print a infinite loop
 *     either match addresses or free the head so cant loop back
 * Return: the count number
 */
size_t print_listint_safe(const listint_t *head)
{
    /* A: we make an array that will store everything from head given */
    size_t node_count = 0;
    size_t index = 0;
    listint_t const **node_array;

    node_array = malloc(sizeof(listint_t *) * 1024);
    if (!node_array)
        exit(98);
    unsigned int i = 0;
    unsigned int flag = 0;

    /* B: while the head is not null, we iterate through */
    while (head != NULL)
    {
        /* C: count is initially 0 and i is 0 so we dont even loop through the first
         * time, we skip this. we assign array to the head and increment head
         * then we increase count so when we loop through again, we can go
         * into the for loop */
        for (i = 0; i < node_count; i++)
        {
            /* D: inside the loop, we check if the head value is equal to the array values
             * if we found a match then we turn the boolean flag on and break and
             * we make the index equal to whatever the i counter was */
            if (head == node_array[i])
            {
                flag = 1;
                index = i;
                break;
            }
            else
                flag = 0;
        }

        /* E: if we found a match, which is a loop, we break out of the while loop */
        if (flag == 1)
            break;
        node_array[node_count] = head;
        head = head->next;
        node_count++;
    }

    /* F: new loop, we will loop through our array values we copied over from head
     * and we print out their pointer address and their value. */
    i = 0;
    while (i < node_count)
    {
        printf("[%p] %d\n", (void *)node_array[i], node_array[i]->n);
        i++;
    }

    /* G: if we had an infinite loop we have a flag check of 1 which will
     * also print out the index which is the last one. */
    if (flag == 1)
    {
        printf("-> [%p] %d\n", (void *)node_array[index], node_array[index]->n);
    }

    free(node_array);
    return (node_count);
}

