# TCP Port Scanner

A simple command-line TCP port scanner written in C using the sockets API.  
It scans a given range of ports on a specified IPv4 address and reports whether each port is open or closed.

## 🛠️ Compilation
Clone this repository
```
git clone https://github.com/depuc/tcp-port-scanner.git
```
Run
```
make
```

To Manually compile the code, use `gcc`:

```bash
gcc portscanner.c -o portscanner
```

## 🚀 Usage
Manually
```
./portscanner <IPv4> <Start_Port> <End_Port>
```

