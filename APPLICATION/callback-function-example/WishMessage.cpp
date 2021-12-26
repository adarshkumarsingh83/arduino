

#include"WishMessage.h"

const String message = "welcome to espark";

void WishMessage::processWishMessage() {
  if (callback) {
    callback(message, message.length());
  }
}

void WishMessage::setCallback(WISH_CALLBACK_SIGNATURE) {
  this->callback = callback;
}

void WishMessage:: loop() {
  processWishMessage();
}
