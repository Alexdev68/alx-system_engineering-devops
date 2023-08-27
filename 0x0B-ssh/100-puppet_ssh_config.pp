# This script uses puppet to make changes to our configuration file
include stdlib

file_line { 'Turn off passwd auth':
path  => '/etc/ssh/ssh_config',
line  => '	PasswordAuthentication off',
match => '^	PasswordAuthentication',
}

file_line { 'IdentityFile':
path => '/etc/ssh/ssh_config',
line => '	IdentityFile ~/.ssh/school'
}
