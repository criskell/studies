package com.criskell.magalums.controller.dto;

import com.criskell.magalums.entity.Channel;
import com.criskell.magalums.entity.Notification;
import com.criskell.magalums.entity.Status;

import java.time.LocalDateTime;

public record ScheduleNotificationDTO(LocalDateTime dateTime,
                                      String destination,
                                      String message,
                                      Channel.Values channel) {
    public Notification toNotification() {
        return new Notification(
                dateTime,
                destination,
                message,
                channel.toChannel(),
                Status.Values.PENDING.toStatus()
        );
    }
}
