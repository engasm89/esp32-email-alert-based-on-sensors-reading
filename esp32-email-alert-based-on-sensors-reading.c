/*
 * Course: Esp32 Email Alert Based On Sensors Reading
 * Platform: ESP32
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Esp32 Email Alert Based On Sensors Reading" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (ESP32)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/esp32-email-alert-based-on-sensors-reading/
 * Repository: https://github.com/engasm89/esp32-email-alert-based-on-sensors-reading
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

// Simulate sensor threshold checks and email alert workflow
#include <stdio.h> // Logs
#include <unistd.h> // Delay

static int temp = 24; // Temperature
static int smoke = 2; // Smoke level

static int send_email(const char* subj, const char* body) { // Email stub
  printf("EMAIL subj='%s' body='%s'\n", subj, body); // Log email
  return 1; // Success
}

int main(void) { // Program entry point
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
} // End of main function
