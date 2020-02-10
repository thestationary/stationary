### Listing the shares:
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




### You can do the following to access the shares:

$ smbclient //10.10.10.178/Data
                        /Users
                        /C$
												/Shared


### to download the files use:
msf > use auxiliary/admin/smb/download_file


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


smbclient  //10.10.10.178/TempUsers -U TempUser
