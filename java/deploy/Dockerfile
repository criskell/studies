FROM eclipse-temurin:25
WORKDIR /app
COPY target/deploy-0.0.1-SNAPSHOT.jar app.jar
EXPOSE 8080
ENTRYPOINT ["java", "-jar", "app.jar"]