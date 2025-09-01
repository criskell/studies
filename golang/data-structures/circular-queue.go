package main

import (
	"errors"
	"fmt"
)

type CircularQueue struct {
	data     []any
	capacity int
	head     int
	tail     int
	size     int
}

func NewCircularQueue(capacity int) *CircularQueue {
	return &CircularQueue{
		data:     make([]any, capacity),
		capacity: capacity,
	}
}

func (q *CircularQueue) IsFull() bool {
	return q.size == q.capacity
}

func (q *CircularQueue) IsEmpty() bool {
	return q.size == 0
}

func (q *CircularQueue) Size() int {
	return q.size
}

func (q *CircularQueue) String() string {
	return fmt.Sprintf("Queue=%v head=%d tail=%d size=%d", q.data, q.head, q.tail, q.size)
}

func (q *CircularQueue) Enqueue(value any) error {
	if q.IsFull() {
		return errors.New("full queue")
	}
	q.data[q.tail] = value
	q.tail = (q.tail + 1) % q.capacity
	q.size++
	return nil
}

func (q *CircularQueue) Dequeue() (any, error) {
	if q.IsEmpty() {
		return nil, errors.New("empty queue")
	}
	val := q.data[q.head]
	q.data[q.head] = nil
	q.head = (q.head + 1) % q.capacity
	q.size--
	return val, nil
}

func main() {
	q := NewCircularQueue(5)

	q.Enqueue(1)
	q.Enqueue(2)
	q.Enqueue(3)

	fmt.Println(q)

	val, _ := q.Dequeue()
	fmt.Println("dequeue:", val)
	fmt.Println(q)

	q.Enqueue(4)
	q.Enqueue(5)
	q.Enqueue(6)
	fmt.Println(q)

	err := q.Enqueue(7)

	if err != nil {
		fmt.Println("err:", err)
	}
}
