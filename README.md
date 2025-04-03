# Minitalk

## Overview
Minitalk is a small data exchange program implemented using UNIX signals. This project focuses on creating a communication system where a client process can send messages to a server process using only SIGUSR1 and SIGUSR2 signals.

## Table of Contents
- [Project Description](#project-description)
- [Features](#features)
- [Technical Concepts](#technical-concepts)
- [Installation](#installation)
- [Usage](#usage)
- [Implementation Details](#implementation-details)
- [Challenges](#challenges)
- [Bonus Features](#bonus-features)

## Project Description
The Minitalk project consists of two programs: a server and a client. The server displays its PID at startup and waits for signals from the client. The client takes the server's PID and a string as arguments, then sends the string to the server by encoding it using only SIGUSR1 and SIGUSR2 signals. The server receives, decodes, and displays the message.

This implementation demonstrates fundamental concepts in inter-process communication, signal handling, and bit manipulation in C programming.

## Features
- Server displays its PID upon launch
- Client sends messages to the server using only SIGUSR1 and SIGUSR2 signals
- Bit-by-bit transmission of characters
- Clean error handling
- Standard and bonus implementations

## Technical Concepts

### UNIX Signals
Signals are software interrupts that provide a way of handling asynchronous events. This project uses:
- **SIGUSR1** and **SIGUSR2**: User-defined signals used to transmit binary data (1s and 0s)
- **Signal Handlers**: Functions that execute when a process receives a specific signal
- **sigaction**: A more robust signal handling API compared to the traditional signal() function

### Process IDs (PIDs)
- Each running process in a UNIX system has a unique process identifier
- The client needs to know the server's PID to send signals to it
- PID validation ensures the target process exists

### Bit Manipulation
- Characters are transmitted by sending their binary representation bit by bit
- Bitwise operations are used for manipulation:
  - Bitshift (`<<`) to test individual bits
  - Bitwise OR (`|=`) to set specific bits in the character being received

### Inter-Process Communication (IPC)
- Processes in UNIX can communicate through various mechanisms
- This project implements IPC through signals, a lightweight communication method

## Installation

Clone the repository and compile the programs:

```bash
git clone https://github.com/hamzamraizik/Minitalk.git
cd Minitalk
make
```

To compile the bonus features:

```bash
make bonus
```

## Usage

### Server
Start the server first to display its PID:

```bash
./server
```

The server will display its PID and wait for incoming messages.

### Client
Use the client to send a message to the server:

```bash
./client <server_pid> "Your message here"
```

Replace `<server_pid>` with the PID displayed by the server.

## Implementation Details

### Server
The server sets up signal handlers for SIGUSR1 and SIGUSR2, then enters an infinite loop waiting for signals. When a signal is received, the handler:

1. Captures the client's PID
2. Assembles the character bit by bit (SIGUSR1 for bit 1, SIGUSR2 for bit 0)
3. Displays the character once all 8 bits are received
4. Resets for the next character

### Client
The client:

1. Validates its command-line arguments
2. Converts the server PID string to an integer
3. Breaks down each character of the message into bits
4. Sends SIGUSR1 for bit 1 and SIGUSR2 for bit 0
5. Adds a small delay between signals to prevent signal loss
6. Sends the null terminator to indicate the end of the message

### Utility Functions
- `ft_atoi`: Converts string to integer with validation
- `usage`: Displays error messages and exits
- `put_nbr`: Displays numbers (used for showing the server PID)

## Challenges

### Signal Reliability
Signals are not guaranteed to be received in the same order they were sent, or even at all. This project addresses this by:
- Adding delays between signals
- Implementing proper error checking
- Handling state between signal receptions

### Bit Manipulation Complexities
Properly receiving and assembling bits into characters requires careful state management:
- Keeping track of how many bits have been received
- Proper bit shifting and setting
- Resetting state variables at appropriate times

### Process Synchronization
Ensuring the client and server remain synchronized:
- Handling potential race conditions
- Managing client identification for multi-client support
- Implementing proper state resets when a new client connects

### Error Handling
Robust error handling for various failure scenarios:
- Invalid PIDs
- Signal transmission failures
- Command-line argument validation

## Bonus Features
The bonus implementation includes:
- Acknowledgment from the server to the client upon message receipt
- Enhanced error handling and resource management

## Conclusion
This project demonstrates fundamental systems programming concepts including signal handling, process communication, and bit-level operations. By implementing a simple yet effective communication protocol using only two signals, it showcases how even limited resources can be leveraged to create functional communication channels between processes.
