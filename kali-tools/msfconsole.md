## Metasploit Console

### Basics
```
$ msfconsole
```
```
search <keywords for exploit-names>
```

once we have got a list of exploits from the previous command
```
use <exploit>                   # choose your exploit
```
```
show options                  # to see requirements of the exploit
```

to change the variables from the requirements
```
set <variable> <value>
```

we can also set a payload(optional) but useful:
```
show payloads
```

```
set payload <path>
```

```
exploit   # if it's a scanner then type "run" 
```