# jammy - compatível com arquitetura ARM e AMD
FROM eclipse-temurin:17.0.8.1_1-jdk-jammy
COPY . .

RUN ./mvnw clean install -DskipTests

ENTRYPOINT ["java", "-jar", "target/backend-0.0.1-SNAPSHOT.jar"]