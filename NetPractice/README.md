*This project has been created as part of the 42 curriculum by msuter.*

# NetPractice

## Description

NetPractice is a networking project from the 42 curriculum. The goal is to understand how TCP/IP addressing works by fixing broken small networks: configuring IP addresses, subnet masks and routing tables so that every host can communicate with the others and with the Internet.

No code is written in this project. The networks are simulated in a web interface, and the project is a hands-on way to learn the fundamentals of IPv4 addressing and subnetting. 10 levels of increasing difficulty must be completed.

### What is a network?

A network is a group of devices (computers, servers, phones, printers...) connected together so they can exchange data. Each device is identified by an **IP address**. Devices in the same network can talk directly to each other; to reach a device in another network, the traffic must go through a **router**.

Key vocabulary:

- **Host**: any device with an IP address on a network.
- **Switch**: connects hosts inside the same network. It does not care about IP addresses.
- **Router**: connects different networks together and forwards packets between them. It has one interface (and one IP address) per network it is connected to.
- **Gateway**: the router address a host uses to leave its own network.
- **Routing table**: a list of rules telling a device where to send a packet depending on its destination (which network, through which gateway).
- **Default route** (`0.0.0.0/0`): the rule used when no other rule matches, typically pointing to the Internet.

### IPv4 addresses

An IPv4 address is a 32-bit number, written as four bytes (octets) in decimal, separated by dots. Each byte goes from 0 to 255.

```
192.168.1.10  =  11000000.10101000.00000001.00001010
```

### What is a mask?

A subnet mask is a 32-bit number made of a series of `1` followed by a series of `0`:

- the bits set to `1` represent the bits **allocated to the network**,
- the bits set to `0` represent the bits **available for the hosts**.

```
255.255.255.0  =  11111111.11111111.11111111.00000000
```

Here, 24 bits are for the network and 8 bits for the hosts.

It can also be written in **CIDR notation** (`/n`), where `n` is simply the number of bits allocated to the network:

```
255.255.255.0    =  /24
255.255.255.128  =  /25
255.255.255.192  =  /26
```

### How to create networks of different sizes

The number of host bits determines the size of the network. Each bit moved from the host part to the network part **divides the network size by 2**.

| CIDR | Host bits | Total addresses | Usable hosts |
|------|-----------|-----------------|--------------|
| /24  | 8         | 256             | 254          |
| /25  | 7         | 128             | 126          |
| /26  | 6         | 64              | 62           |
| /27  | 5         | 32              | 30           |
| /28  | 4         | 16              | 14           |
| /29  | 3         | 8               | 6            |
| /30  | 2         | 4               | 2            |
| /31  | 1         | 2               | 0 (2 on point-to-point links, special case) |
| /32  | 0         | 1               | single host  |

Two addresses in every network are reserved:

- the **network address** (all host bits at `0`): identifies the network itself,
- the **broadcast address** (all host bits at `1`): used to reach every host of the network.

So usable hosts = `total addresses - 2`. This count must also include the router interface if one is connected to the network.

Rules to remember when choosing a range:

1. A network of size `S` must **start on a multiple of `S`**. For example, a block of 64 addresses can only start at `.0`, `.64`, `.128` or `.192`.
2. Two networks must **never overlap**.
3. A host address must be **neither the network address nor the broadcast address**.
4. A host and its gateway must be **in the same network** (same network part).
5. Every router interface must have an IP in the network it is plugged into.

Example of splitting a `/24` (256 addresses) in blocks:

```
/24 -> 2 x /25 (128 each)
/25 -> 2 x /26 (64 each)
/26 -> 2 x /27 (32 each)
...
```
## Instructions

NetPractice is done on a dedicated web interface provided by 42. Nothing has to be compiled or installed.

### Running the training interface

1. Download the archive attached to the project page and extract it in any folder.
2. In this folder, run the `run.sh` script. It launches a local web server and opens your default browser on the interface.
3. If `run.sh` does not work, start the server manually with `python3 -m http.server 49242` (the port can be changed), then open `http://localhost:49242` in your browser.
4. **Enter your 42 login** (`msuter`) in the "Training" tab and click **Start!**. This is essential: the configuration of each level is generated from the login.

### Solving the levels

1. For each level (1 to 10), read the goals displayed at the top and study the network diagram.
2. Modify only the unshaded fields: IP addresses, subnet masks and routing table entries.
3. Click **Check again** to validate the configuration. The logs at the bottom of the page explain why a packet does not reach its destination.
4. When the level is validated, a **Next level** button appears.

### Exporting the configuration

Before moving to the next level, click **Get my config** to download the configuration file of the level you just solved. One file must be exported per level.

### Submission

- 10 exported configuration files (one per level) must be placed at the **root of the Git repository**, next to this `README.md`.
- Only the work in the repository is evaluated during the defense.
- During the defense, three random levels must be solved in a limited amount of time, without any external tool (a simple calculator such as `bc` is tolerated).

## Resources

### Networking concepts studied

- **TCP/IP addressing**: IPv4 addresses, network part and host part, network address and broadcast address
- **Subnet masks** and **CIDR notation**: subnetting and network sizes
- **Default gateways** and **routing tables**: default route, forwarding of packets between networks
- **Routers and switches**: role of each device, link layer vs network layer
- **OSI layers**

### References

- 42 NetPractice subject (PDF)
- An online binary-decimal converter, to convert IP addresses and masks between binary and decimal
- Claude (AI assistant), used as a tutor to explain networking concepts

### Use of AI

AI (Claude) was used for two tasks only:

- **Learning**: to get explanations of networking concepts (what a mask is, how CIDR notation and network sizes work, the role of a gateway).
- **Documentation**: to help structure and write this README.

The 10 levels of the project were solved personally, and the concepts were understood and verified before being reported here.
