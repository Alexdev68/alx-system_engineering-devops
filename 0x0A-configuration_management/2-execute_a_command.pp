# This script kills a process named killmenow

exec { 'killer':
command => '/usr/bin/pkill killmenow',
}
