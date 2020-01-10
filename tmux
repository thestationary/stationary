config file name should be .tmux.conf

the prefix key is Ctrl-a



https://tmuxcheatsheet.com/


http://atkinsam.com/documents/tmux.pdf



my tmux keys

<prefix> = Ctrl+a

<prefix> [		edit mode, scroll on output with the arrows, exit edit mode with esc


=Create Panes and Tabs

<prefix> c		new tab

<prefix> -		new horizontal pane

<prefix> _		new vertical pane


=Navigate through panes

<pref> <vim_navigation_keys>
or 
<pref> arrows


=Navigate through tabs

<prefix> <tab_number>
or
<prefix> Ctrl+<vim_navigation_keys>


=Rename tab

<prefix> ,


==Close tab or pane

Ctrl+d			(End of input)



==Session creation


$ tmux new -s <session name>


