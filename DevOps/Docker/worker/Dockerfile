FROM maven:3.5-jdk-8-alpine as builder
WORKDIR /builder
COPY . ./
RUN mvn dependency:resolve && mvn package

FROM openjdk:8-jre-alpine
COPY --from=builder /builder/target .
CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]