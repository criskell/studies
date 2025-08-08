/opt/tomcat/bin/shutdown.sh && /opt/tomcat/bin/startup.sh
mvn clean package && sudo cp ./target/jsf-test-1.0-SNAPSHOT.war /opt/tomcat/webapps 