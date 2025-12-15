provider "aws" {
  region = "us-east-1"
}

resource "aws_instance" "server" {
  ami           = "ami-068c0051b15cdb816"
  instance_type = "t2.nano"
  user_data     = file("user_data.sh")

  vpc_security_group_ids = [aws_security_group.security_group.id]
  key_name               = aws_key_pair.keypair.key_name
}

resource "aws_security_group" "security_group" {
  name        = "security-group"
  description = "Allow HTTP and internet access"

  ingress {
    from_port = 80
    to_port   = 80
    protocol  = "tcp"
    cidr_blocks = [
      "0.0.0.0/0"
    ]
  }

  ingress {
    from_port = 22
    to_port   = 22
    protocol  = "tcp"
    cidr_blocks = [
      "0.0.0.0/0"
    ]
  }

  egress {
    from_port   = 0
    to_port     = 65535
    protocol    = "tcp"
    cidr_blocks = ["0.0.0.0/0"]
  }
}

resource "aws_key_pair" "keypair" {
  key_name   = "terraform-keypair"
  public_key = file("~/.ssh/id_rsa_deploy_aws.pub")
}
