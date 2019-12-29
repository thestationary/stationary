
### wfuzz




```
wfuzz -t 200 -u http://10.10.10.168:8080/FUZZ/SuperSecureServer.py -w /usr/share/wordlists/dirb/common.txt  --hc 404
```

-t <number of threads>

in url we point with FUZZ the directory to dirbust

--hc 404    is used to hide the 404 codes ("not found" code)

in case we are searching for a specific code we add the arg:
--h <desired code>


we could also fuzz level one like:

```
wfuzz -t 200 -u http://10.10.10.168:8080/FUZZ -w /usr/share/wordlists/dirb/common.txt  --hc 404
```
