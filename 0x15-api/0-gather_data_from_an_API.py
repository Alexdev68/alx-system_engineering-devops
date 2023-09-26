#!/usr/bin/python3
'''This script uses a `REST API` for a given employee ID, returns
   information about his/her TODO list progress.
'''
import json
from sys import argv
import urllib.request


def get_employees_todos(id):
    '''This function is where most of the work is done.'''
    url = 'https://jsonplaceholder.typicode.com'

    with urllib.request.urlopen(f'{url}/todos?userId={id}') as response:
        todos = json.loads(response.read())

    with urllib.request.urlopen(f'{url}/users/{id}') as response:
        user_info = json.loads(response.read())
        Name = user_info.get('name')

    completed = [todo for todo in todos if todo['completed']]
    n_comp = len(completed)
    tot_num = len(todos)

    print(f'Employee {Name} is done with tasks({n_comp}/{tot_num}):')

    for to in completed:
        print(f'\t {to["title"]}')


if __name__ == '__main__':
    get_employees_todos(argv[1])
