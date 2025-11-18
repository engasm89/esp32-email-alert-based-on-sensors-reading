// Simulate sensor threshold checks and email alert workflow
#include <stdio.h> // Logs
#include <unistd.h> // Delay

static int temp = 24; // Temperature
static int smoke = 2; // Smoke level

static int send_email(const char* subj, const char* body) { // Email stub
  printf("EMAIL subj='%s' body='%s'\n", subj, body); // Log email
  return 1; // Success
}

int main(void) { // Entry
  printf("ESP32 Email Alert Based on Sensors Reading\n"); // Title
  for (int i = 0; i < 15; ++i) { // Loop
    temp += (i % 3 == 0); // Temp drift
    smoke = (i % 5 == 0) ? 6 : 2; // Smoke spikes
    if (temp >= 28) { // Temp threshold
      send_email("High Temp", "Temperature exceeded 28C"); // Alert
    } // End temp alert
    if (smoke >= 5) { // Smoke threshold
      send_email("Smoke Alert", "Smoke level too high"); // Alert
    } // End smoke alert
    printf("SENSORS temp=%d smoke=%d\n", temp, smoke); // Log
    usleep(200000); // Delay
  } // End loop
  return 0; // Exit
} // End main
