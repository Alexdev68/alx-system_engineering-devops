#!/usr/bin/env ruby
matched = ARGV[0].scan(/\[from:(\W?\w+)\] \[to:(\W?\w+)\] \[flags:(.{0,12}|.{0,13})\]/)
puts matched.join(",")
