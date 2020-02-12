## smbclient
run
`smbclient -L //ip`
to list the Shares


then 
`smbclient //ip/<a share>/ '
for default

where <a share> is a share from the ones we
found on the `smbclient -L //ip` command.

`smbclient //ip/<a share>/ -U <username>`

and then will be prompted for password
