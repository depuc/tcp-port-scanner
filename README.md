# TCP Port Scanner

A simple command-line TCP port scanner written in C using the sockets API.  
It scans a given range of ports on a specified IPv4 address and reports whether each port is open or closed.

## 🛠️ Compilation

To compile the code, use `gcc`:

```bash
gcc portscanner.c -o portscanner
```

## 🚀 Usage
```
./portscanner <IPv4> <Start_Port> <End_Port>
```
