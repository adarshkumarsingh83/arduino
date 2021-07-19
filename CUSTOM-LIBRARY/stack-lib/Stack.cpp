
#include "Stack.h"
#include "Arduino.h"

template <class T>
boolean Stack<T>::push(const T &value) {
  if (!isFull()) {
    _index = _index + 1;
    _data[_index] = value;
    _itemCount++;
    Serial.print(_stackName + " DATA INSERTED ");
    Serial.println(value);
    return true;
  }
  return false;
}

template <class T>
inline T Stack<T>::pop() {
  if (!isEmpty()) {
    T value = _data[_index];
    _data[_index] = T();
    _index = _index - 1;
    --_itemCount;
    return value;
  }
  return T();
}

template <class T>
boolean Stack<T>::isEmpty() {
  if (_index == -1) {
    return true;
  } else {
    return false;
  }
}

template <class T>
boolean Stack<T>::isFull() {
  if (_index == _stackSize) {
    return true;
  } else {
    return false;
  }
}

template <class T>
void Stack<T>::resetStack() {
  Serial.print(_stackName + " RESETTING STACK ");
  Serial.println();
  _index = -1;
  _itemCount = 0;
  for (int i = 0; i < _stackSize; i++) {
    _data[i] = T();
  }
}

template <class T>
void Stack<T>::displayStack() {
  Serial.print(_stackName + " DATA => ");
  for (int i = 0; i < _index; i++) {
    Serial.print(_data[i]);
    Serial.print("  ");
  }
  Serial.println();
}
