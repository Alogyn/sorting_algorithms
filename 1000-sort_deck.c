#include "deck.h"

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Double pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t i = 0;
	size_t j;

    if (deck == NULL || *deck == NULL)
        return;

    /* Convert the doubly linked list to an array for sorting */
    deck_node_t *current = *deck;
    card_t *cards[52];

    while (current != NULL)
    {
        cards[i] = (card_t *)current->card;
        current = current->next;
        i++;
    }

    /* Use qsort to sort the array of cards */
    qsort(cards, i, sizeof(card_t *), compare_cards);

    /* Rebuild the sorted deck as a doubly linked list */
    *deck = NULL;
    for (j = 0; j < i; j++)
    {
        deck_node_t *new_node = malloc(sizeof(deck_node_t));
        if (new_node == NULL)
        {
            /* Handle memory allocation failure */
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        new_node->card = cards[j];
        new_node->prev = NULL;
        new_node->next = *deck;

        if (*deck != NULL)
            (*deck)->prev = new_node;

        *deck = new_node;
    }
}

/**
 * compare_cards - Compare function for qsort to compare cards
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 * Return: Integer less than, equal to, or greater than zero
 * if the first card is considered to be respectively less than,
 * equal to, or greater than the second.
 */
int compare_cards(const void *card1, const void *card2)
{
    return strcmp((*(card_t **)card1)->value, (*(card_t **)card2)->value);
}

