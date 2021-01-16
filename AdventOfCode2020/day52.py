import os
THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
input_file = os.path.join(THIS_FOLDER, 'input-day51.txt')

def get_seat_id(seat):
    row_min = 0
    row_max = 127
    col_min = 0
    col_max = 7
    idx = 0

    while idx < 10:
        if idx < 7:
            if seat[idx] == 'F':
                row_max = (row_min + row_max) // 2
            else:
                row_min = (row_min + row_max) // 2 + 1
        else:
            if seat[idx] == 'L':
                col_max = (col_min + col_max) // 2
            else:
                col_min = (col_min + col_max) // 2 + 1
        idx += 1

    return row_min * 8 + col_min

lowest_seat_id = 1e5+7
highest_seat_id = 0
k = []
with open(input_file) as f:
    for seat in f:
        seat_id = get_seat_id(seat)
        highest_seat_id = max(highest_seat_id, seat_id)
        lowest_seat_id = min(lowest_seat_id, seat_id)
        k += [seat_id]

print(sum([i for i in range(lowest_seat_id, highest_seat_id + 1)]) - sum(k))