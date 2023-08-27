# This script uses puppet to make changes to our configuration file

file { '/etc/ssh/ssh_config':
ensure  => present,
content => @(END);
Host 303903-web-01
	HostName 52.91.126.140
	User ubuntu
	IdentityFile ~/.ssh/school
	PasswordAuthentication no
	ChallengeResponseAuthentication no
  END
}

