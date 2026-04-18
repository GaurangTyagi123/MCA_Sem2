- Name : Gaurang Tyagi
- Roll No : 16

# Practical 1

## Task 1
### Active Interface
```bash
ip -o -4 addr show | awk '{print $2}'
```
* ### OUTPUT
![1774166972693](image/practical_1/1774166972693.png)

### Default Gateway
```bash
echo -e "\e[31;1mdefault gateway is\e[0m : $(ip route show | grep "default via") "
```

* ### OUTPUT
![1774166996899](image/practical_1/1774166996899.png)

### IPV4/IPV6
```bash
echo -e "\e[31;1mIPV4 address is\e[0m : $(ifconfig | grep -m 1 "inet" | sed s/[[:space:]]*//) "
echo -e "\e[31;1mIPV4 address is\e[0m : $(ifconfig | grep -m 1 "inet6" | sed s/[[:space:]]*//) "
```

* ### OUTPUT
![1774167016964](image/practical_1/1774167016964.png)

### DNS Servers
```bash
echo -e "\e[31;1mDNS is : \e[0m $(cat /etc/resolv.conf | grep "nameserver")"
```

* ### OUTPUT
![1774167039019](image/practical_1/1774167039019.png)

### why does the output show so many interfaces?
```
Output shows multiple interfaces because operating system supports multiple networking devices and virtual networks (like tailscale )
```
* ### OUTPUT

### determine whether the IP address of your machine is a private IP address or a public IP address?

```
IP address of my machine is private as the default gateway lies in the private IP address range of 192.168.0.0–192.168.255.255 (class C)
```

### identify the public IP address seen from the internet from any website of your choice.
![1774167175198](image/practical_1/1774167175198.png)

### 2-3 lines interpretation of what an attacker could infer
    - From all of the above information an attacker could:
        - get my exact location 
        - get my network range for lateral movement within the network
        - poison my DNS record
        - perform DDOs attack

## Task 2

### Step 1 : Run repeated (at least 10) probes to ->
    | Target | Packet Loss | RTT (min/avg/max) | Effect of DNS Resolution | Observation |
    |---|---|---|---|---|
    | **Gateway** | 0 packet loss |1.624/3.279/6.338 ms | None | There is no effect of DNS Resolution as gateway is part of the private network |
    | **8.8.8.8** | 0 packet loss | 7.972/14.927/45.685 ms | None | It is slower than the gateway as it is not part of the private network |
    | **gaurang.work** | 0 packet loss | 164.334/218.968/278.030 ms | None | It is the slowest because the server is located in europe |

### Step 2 : Ping the destination of your choice with 10 echo Request messages, each of which has a Data field of 1000 bytes.
    **OUTPUT**
    ![1774168943230](image/practical_1/1774168943230.png)

## Task 3

### Step 1 : Run traceroute to 3 destinations

| target | # of Hops | first hop | second hop | final destination | screenshot |
|---|---|---|---|---|---|
| google.com | 7 | 192.168.1.1 | 182.64.8.1 | 142.250.182.238 | ![1774169490163](image/practical_1/1774169490163.png) |
| youtube.com | 12 | 192.168.1.1 | 182.64.8.1 | 142.250.238.81 | ![1774169746148](image/practical_1/1774169746148.png) |
| gaurang.work | 7 | 192.168.1.1 | 182.64.8.1 | 104.21.47.134 | ![1774169810642](image/practical_1/1774169810642.png) |

* Why might some hops show *** request timed out even when the destination is reachable?
```
"***" means traceroute did not recieve ICMP time exceeeded responses which can be due to firewall on the intermediate server.
```
* What can an attacker infer from traceroute results about a target network?
```
From traceroute results an attacker can infer:
    1. Network path and topology i.e., the sequence of routers between the attacker and the target
    2. Number of hops to reach the target
    3. ISPs involved in routing traffic
    4. Possible geographic locations of the routers based on hostnames or latency
    5. Security devices such as firewalls if responses suddenly stop (***)
```
* Why is the first hop usually your local router or gateway?
```
The first hop is usually your local router or gateway because packets from my computer must first travel to the default gateway to reach external networks as it is part of the local network. The router forwards packets from the local network to the internet.
Therefore, traceroute first encounters the local router, which becomes hop 1.
```
* Why may the second or third hop often belong to the ISP?
```
The second or third hop often belongs to the Internet Service Provider (ISP) because after leaving the local router, packets enter the ISP’s network infrastructure as ISPs operate multiple routers that handle routing traffic to other networks.
These routers appear early in traceroute results since they connect user networks to the broader internet.
Thus, early hops typically show routers owned by the ISP.
```
* How could traceroute help in identifying whether a service is hosted locally, in another region, or behind a cloud provider?
```
Traceroute can help identify hosting locations by analyzing:

1. Latency
    - Low latency means service likely hosted nearby.
    - High latency means service likely hosted in another region or country.

2. Router hostnames
    - Hostnames sometimes include city or region codes.

3. Infrastructure names
    Routers containing names of cloud or CDN providers may indicate hosting with platforms like Cloudflare, Amazon Web Services, or Akamai.
```
* Why is traceroute useful to both defenders and attackers?
```
Traceroute is useful for both because it provides insight into network routing and structure.

For defenders:

    1. Troubleshoot network connectivity problems
    2. Identify routing issues or bottlenecks
    3. Monitor network performance
    4. Diagnose packet loss and latency problems

For attackers:

    1. Map network paths and infrastructure
    2. Identify potential entry points or security devices
    3. Gather reconnaissance information about ISPs and hosting providers
    4. Plan targeted attacks based on network structure
```
## Task 4

### Step 1 : Perform a basic DNS Lookup to verify that the domain resolves successfully.
- www.google.com
![1774172257408](image/practical_1/1774172257408.png)
- www.du.ac.in
![1774172271605](image/practical_1/1774172271605.png)

### Step 2 : Run the same query multiple times. Observe whether the result suggests single-host resolution, redundancy, or load balancing.
- output
![1774172538373](image/practical_1/1774172538373.png)
![1774172553028](image/practical_1/1774172553028.png)
![1774172566997](image/practical_1/1774172566997.png)
- **observation**
    - It returns same IP every time therefore the result suggests single-host resolution

### Step 3 : For each of the two domains, collect the following DNS record types:
* ### A
* ### AAAA
* ### NS
* ### MX
* ### TXT
* ### Reverse lookup (PTR) for at least one returned IP address

| target | A | AAAA | NS | MX | TXT | Reverse Lookup |
|---|---|---|---|---|---|---|
| www.google.com | 142.251.156.119 | 2001:4860:482c:7700:: | ns1.google.com. dns-admin.google.com | aspmx.l.google.com | v=spf1 include:_spf.google.com | None |
| www.du.ac.in | 34.93.1.114 | None | himalaya.du.ac.in. | None | None | None |

### Step 4 : for each of the domains

- www.google.com

| Record Type | Observed Output | Technical Meaning | Reconnaissance Value |
|-------------|-----------------|-------------------|----------------------|
| A | 142.251.156.119 | Maps domain to IPv4 address | Reveals hosting IP |
| AAAA | 2001:4860:482c:7700:: | Maps domain to IPv6 | Shows IPv6 infrastructure |
| NS | ns1.google.com. dns-admin.google.com | Authoritative name servers | Reveals DNS provider |
| MX | aspmx.l.google.com | Mail server for domain | Shows email infrastructure |
| TXT | v=spf1 include:_spf.google.com | SPF email policy | Reveals mail services used |
| Reverse Lookup | None | Hostname for IP | May reveal hosting provider |

- www.du.ac.in

| Record Type | Observed Output | Technical Meaning | Reconnaissance Value |
|-------------|-----------------|-------------------|----------------------|
| A | 34.93.1.114 | Maps domain to IPv4 address | Reveals hosting IP |
| AAAA | None | Maps domain to IPv6 | Shows IPv6 infrastructure |
| NS | himalaya.du.ac.in. | Authoritative name servers | Reveals DNS provider |
| MX | None| Mail server for domain | Shows email infrastructure |
| TXT | None | SPF email policy | Reveals mail services used |
| Reverse Lookup | None | Hostname for IP | May reveal hosting provider |

### Step 5 : Identify which one exposes more useful reconnaissance information and why.

```
Domain A exposes more reconnaissance information because its TXT records reveal SPF policies and external services, while the reverse lookup also identifies the hosting provider
```