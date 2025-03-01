package com.criskell.magalums.service;

import com.criskell.magalums.controller.dto.ScheduleNotificationDTO;
import com.criskell.magalums.entity.Notification;
import com.criskell.magalums.entity.Status;
import com.criskell.magalums.repository.NotificationRepository;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.List;
import java.util.Optional;
import java.util.function.Consumer;

@Service
public class NotificationService {
    private final NotificationRepository notificationRepository;

    public NotificationService(NotificationRepository notificationRepository) {
        this.notificationRepository = notificationRepository;
    }

    public void scheduleNotification(ScheduleNotificationDTO scheduleNotificationDTO) {
        notificationRepository.save(scheduleNotificationDTO.toNotification());
    }

    public Optional<Notification> findById(Long notificationId) {
        return notificationRepository.findById(notificationId);
    }

    public void cancelNotification(Long notificationId) {
        findById(notificationId).ifPresent(notification -> {
            notification.setStatus(Status.Values.CANCELLED.toStatus());
            notificationRepository.save(notification);
        });
    }

    public void checkAndSend(LocalDateTime dateTime) {
        var notifications = notificationRepository.findByStatusInAndDateTimeBefore(
                List.of(Status.Values.PENDING.toStatus(), Status.Values.ERROR.toStatus()),
                dateTime
        );

        notifications.forEach(sendNotification());
    }

    private Consumer<Notification> sendNotification() {
        return n -> {
            // TODO: Send notification to specified channel.

            n.setStatus(Status.Values.SUCCESS.toStatus());
            notificationRepository.save(n);
        };
    }
}
