#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char url[21];  // assume that any url will only be 21 characters long
  struct Node* prev;
  struct Node* next;
} Node;

typedef struct {
  Node* current;
} BrowserHistory;

// Function to create a new node
Node* createNode(const char* url) {
  Node* tmp = (Node*)malloc(sizeof(Node));

  tmp->next = NULL;
  tmp->prev = NULL;
  // tmp->url = url;
  if (strlen(url) >= 21) {
    // panic;
    printf("I cannot handle this big url!\n");
    exit(1);
  }
  strcpy(tmp->url, url);
  return tmp;
}

// Function to initialize the BrowserHistory object
BrowserHistory* browserHistoryCreate(char* homepage) {
  // to do: Initializes the BrowserHistory object with the homepage of the browser.
  BrowserHistory* bh = (BrowserHistory*)malloc(sizeof(BrowserHistory));
  bh->current = createNode(homepage);
  return bh;
}

// Function to visit a new URL
void browserHistoryVisit(BrowserHistory* bh, char* url) {
  // to do: Visits url from the current page. It clears up all the forward history.
  Node* tmp = createNode(url);
  Node* current = bh->current->next;
  // bh->current = tmp;
  while (current != NULL) {
    Node* next = current->next;
    free(current);
    current = next;
  }

  tmp->prev = bh->current;
  bh->current->next = tmp;
  bh->current = tmp;
}

// Function to move back in history
char* browserHistoryBack(BrowserHistory* bh, int steps) {
  // to do: Move steps back in history. If you can only return x steps in the history and steps > x,
  // you will return only x steps.
  Node* current = bh->current;
  while (steps > 0 && current->prev != NULL) {
    steps--;
    current = current->prev;
  }

  // Return the current url after moving back in history at most steps.
  bh->current = current;
  return current->url;
}

// Function to move forward in history
char* browserHistoryForward(BrowserHistory* bh, int steps) {
  // to do: Move steps forward in history. If you can only forward x steps in the history and steps
  // > x, you will forward only x steps.
  Node* current = bh->current;
  while (steps > 0 && current->next != NULL) {
    steps--;
    current = current->next;
  }
  // Return the current url after forwarding in history at most steps.
  bh->current = current;
  return current->url;
}

// Function to free the BrowserHistory object
void browserHistoryFree(BrowserHistory* bh) {
  // to do
  Node* current = bh->current;
  // Go to the beginning
  while (current->prev != NULL) {
    current = current->prev;
  }
  while (current != NULL) {
    bh->current = current;
    current = current->next;
    free(bh->current);
  }
  free(bh);
}

// Example usage
int main() {
  BrowserHistory* browserHistory = browserHistoryCreate("google.com");
  browserHistoryVisit(browserHistory, "leetcode.com");
  browserHistoryVisit(browserHistory, "facebook.com");
  browserHistoryVisit(browserHistory, "youtube.com");
  printf("Current URL: %s\n", browserHistoryBack(browserHistory, 1));     // facebook.com
  printf("Current URL: %s\n", browserHistoryBack(browserHistory, 1));     // leetcode.com
  printf("Current URL: %s\n", browserHistoryForward(browserHistory, 1));  // facebook.com
  browserHistoryVisit(browserHistory, "linkedin.com");
  printf("Current URL: %s\n", browserHistoryForward(browserHistory, 2));  // linkedin.com
  printf("Current URL: %s\n", browserHistoryBack(browserHistory, 2));     // leetcode.com
  printf("Current URL: %s\n", browserHistoryBack(browserHistory, 7));     // google.com

  browserHistoryFree(browserHistory);
  return 0;
}